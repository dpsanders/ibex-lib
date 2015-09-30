//============================================================================
//                                  I B E X                                   
// File        : ibex_Solver.cpp
// Author      : Gilles Chabert
// Copyright   : Ecole des Mines de Nantes (France)
// License     : See the LICENSE file
// Created     : May 13, 2012
// Last Update : May 13, 2012
//============================================================================

#include "ibex_Solver.h"


#include "ibex_NoBisectableVariableException.h"
#include <cassert>

using namespace std;

namespace ibex {

Solver::Solver(Ctc& ctc, Bsc& bsc, CellBuffer& buffer) :
  ctc(ctc), bsc(bsc), buffer(buffer), time_limit(-1), cell_limit(-1), trace(0), time(0), impact(BitSet::all(ctc.nb_var))  {
	nb_cells=0;
}


  Cell* Solver::root_cell(const IntervalVector& init_box) {return (new Cell(init_box));}

  void Solver::start(const IntervalVector& init_box) {
	buffer.flush();

	Cell* root= root_cell(init_box); 

	// add data required by this solver
	root->add<BisectedVar>();

	// add data required by the bisector
	bsc.add_backtrackable(*root);

	buffer.push(root);

	IntervalVector tmpbox(init_box.size());

	Timer::start();

}

  pair<Cell*,Cell*> Solver::bisect(Cell& c,IntervalVector&box1, IntervalVector&box2){
    return c.bisect(box1,box2);
  }

  bool Solver::next(std::vector<IntervalVector>& sols) {
	try  {
		while (!buffer.empty()) {

		  if (trace==2) {cout << buffer << endl; cout <<buffer.top()->box << endl;}

			Cell* c=buffer.top();
			//		        cout << " points " << c->get_points().size() << endl;
			//	for (int i=0;i<c->get_points().size();i++) cout << i << "  " <<  (c->get_points())[i];
			//			cout << endl;
			int v=c->get<BisectedVar>().var;      // last bisected var.
				 
			if (v!=-1)     // no root node :  impact set to 1 for last bisected var only
			  impact.add(v);
			else                                // root node : impact set to 1 for all variables
			  impact.fill(0,ctc.nb_var-1);

				
				
			precontract(*c);

			ctc.contract(c->box,impact);

			if (c->box.is_empty()) {
			  postcontract(*c);
			  delete buffer.pop();
			  impact.remove(v);
			}
                        else {
			
			postcontract(*c);
			if (v!=-1)
			  impact.remove(v);
			else                              // root node : impact set to 0 for all variables after contraction
			  impact.clear();

				

			try {
			  prebisect(*c);

			  pair<IntervalVector,IntervalVector> boxes=bsc.bisect(*c);

			  pair<Cell*,Cell*> new_cells = bisect(*c,boxes.first,boxes.second);
					//	pair<Cell*,Cell*> new_cells = c->bisect(boxes.first,boxes.second);

					delete buffer.pop();
					buffer.push(new_cells.first);

					buffer.push(new_cells.second);

					nb_cells+=2;
					if (cell_limit >=0 && nb_cells>=cell_limit) throw CellLimitException();}

				catch (NoBisectableVariableException&) {
				  if (solution_test (*c))
				    new_sol(sols, c->box);
				  delete buffer.pop();
				  return !buffer.empty();
				  // note that we skip time_limit_check() here.
				  // In the case where "next" is called by "solve",
				  // and if time has exceeded, the exception will be raised by the
				  // very next call to "next" anyway. This holds, unless "next" finds
				  // new solutions again and again endlessly. So there is a little risk
				  // of uncaught timeout in this case (but this case is probably already
				  // an error case).
				}
				time_limit_check();
			}
			
		}
	}
	catch (TimeOutException&) {
		cout << "time limit " << time_limit << "s. reached " << endl; return false;
	}
	catch (CellLimitException&) {
		cout << "cell limit " << cell_limit << " reached " << endl;
	}

	Timer::stop();
	time+= Timer::VIRTUAL_TIMELAPSE();

	return false;

  }

vector<IntervalVector> Solver::solve(const IntervalVector& init_box) {
	vector<IntervalVector> sols;
	start(init_box);
	while (next(sols)) { }
	return sols;
}

void Solver::time_limit_check () {
	Timer::stop();
	time += Timer::VIRTUAL_TIMELAPSE();
	if (time_limit >0 &&  time >=time_limit) throw TimeOutException();
	Timer::start();
}


void Solver::new_sol (vector<IntervalVector> & sols, IntervalVector & box) {
	sols.push_back(box);
	cout.precision(12);
	if (trace >=1)
	  cout << " sol " << sols.size() << " nb_cells " <<  nb_cells << " "  << sols[sols.size()-1] <<   endl;


}

 
} // end namespace ibex



