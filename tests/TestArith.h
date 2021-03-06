/* ============================================================================
 * I B E X - Test of interval operations
 * ============================================================================
 * Copyright   : Ecole des Mines de Nantes (FRANCE)
 * License     : This program can be distributed under the terms of the GNU LGPL.
 *               See the file COPYING.LESSER.
 *
 * Author(s)   : Gilles Chabert
 * Created     : Dec 07, 2011
 * Last Update : Jul 16, 2012
 * ---------------------------------------------------------------------------- */

#ifndef __TEST_ARITH_H__
#define __TEST_ARITH_H__

#include "cpptest.h"
#include "ibex_Interval.h"
#include "utils.h"

using namespace ibex;

class TestArith : public TestIbex {
public:
	TestArith() {

		TEST_ADD(TestArith::minus01);
		TEST_ADD(TestArith::minus02);
		TEST_ADD(TestArith::minus03);
		TEST_ADD(TestArith::minus04);

		TEST_ADD(TestArith::add01);
		TEST_ADD(TestArith::add02);
		TEST_ADD(TestArith::add03);
		TEST_ADD(TestArith::add04);
		TEST_ADD(TestArith::add05);
		TEST_ADD(TestArith::add06);
		TEST_ADD(TestArith::add07);
		TEST_ADD(TestArith::add08);
		TEST_ADD(TestArith::add09);
		TEST_ADD(TestArith::add10);
		TEST_ADD(TestArith::add11);

		TEST_ADD(TestArith::mul01);
		TEST_ADD(TestArith::mul02);
		TEST_ADD(TestArith::mul03);
		TEST_ADD(TestArith::mul04);
		TEST_ADD(TestArith::mul05);
		TEST_ADD(TestArith::mul06);
		TEST_ADD(TestArith::mul07);
		TEST_ADD(TestArith::mul08);
		TEST_ADD(TestArith::mul09);
		TEST_ADD(TestArith::mul10);
		TEST_ADD(TestArith::mul11);
		TEST_ADD(TestArith::mul12);
		TEST_ADD(TestArith::mul13);
		TEST_ADD(TestArith::mul14);
		TEST_ADD(TestArith::mul15);
		TEST_ADD(TestArith::mul16);
		TEST_ADD(TestArith::mul17);
		TEST_ADD(TestArith::mul18);
		TEST_ADD(TestArith::mul19);

		TEST_ADD(TestArith::mulMM01);

		TEST_ADD(TestArith::div01);
		TEST_ADD(TestArith::div02);
		TEST_ADD(TestArith::div03);
		TEST_ADD(TestArith::div04);
		TEST_ADD(TestArith::div05);
		TEST_ADD(TestArith::div06);
		TEST_ADD(TestArith::div07);
		TEST_ADD(TestArith::div08);
		TEST_ADD(TestArith::div09);
		TEST_ADD(TestArith::div10);
		TEST_ADD(TestArith::div11);
		TEST_ADD(TestArith::div12);
		TEST_ADD(TestArith::div13);
		TEST_ADD(TestArith::div14);
		TEST_ADD(TestArith::div15);
		TEST_ADD(TestArith::div16);
		TEST_ADD(TestArith::div17);

		TEST_ADD(TestArith::div2_01);
		TEST_ADD(TestArith::div2_02);
		TEST_ADD(TestArith::div2_03);
		TEST_ADD(TestArith::div2_04);
		TEST_ADD(TestArith::div2_05);
		TEST_ADD(TestArith::div2_06);
		TEST_ADD(TestArith::div2_07);
		TEST_ADD(TestArith::div2_08);
		TEST_ADD(TestArith::div2_09);
		TEST_ADD(TestArith::div2_10);
		TEST_ADD(TestArith::div2_11);
		TEST_ADD(TestArith::div2_12);
		TEST_ADD(TestArith::div2_13);

		TEST_ADD(TestArith::log01);
		TEST_ADD(TestArith::log02);
		TEST_ADD(TestArith::log03);
		TEST_ADD(TestArith::log04);
		TEST_ADD(TestArith::log05);
		TEST_ADD(TestArith::log06);

		TEST_ADD(TestArith::sin01);
		TEST_ADD(TestArith::sin02);
		TEST_ADD(TestArith::sin03);
		TEST_ADD(TestArith::sin04);
		TEST_ADD(TestArith::sin05);
		TEST_ADD(TestArith::sin06);
		TEST_ADD(TestArith::sin07);
		TEST_ADD(TestArith::sin08);
		TEST_ADD(TestArith::sin09);
		TEST_ADD(TestArith::sin10);
		TEST_ADD(TestArith::sin11);
		TEST_ADD(TestArith::sin12);
		TEST_ADD(TestArith::sin13);

		TEST_ADD(TestArith::tan01);
		TEST_ADD(TestArith::tan02);
		TEST_ADD(TestArith::tan03);
		TEST_ADD(TestArith::tan04);
		TEST_ADD(TestArith::tan05);

		TEST_ADD(TestArith::pow01);
		TEST_ADD(TestArith::pow02);
		TEST_ADD(TestArith::pow03);
		TEST_ADD(TestArith::pow04);
		TEST_ADD(TestArith::pow05);
		TEST_ADD(TestArith::pow06);
		TEST_ADD(TestArith::pow07);
		TEST_ADD(TestArith::pow08);
		TEST_ADD(TestArith::pow09);
		TEST_ADD(TestArith::pow10);
		TEST_ADD(TestArith::pow11);
		TEST_ADD(TestArith::pow12);
		TEST_ADD(TestArith::pow13);

		TEST_ADD(TestArith::root01);
		TEST_ADD(TestArith::root02);

		TEST_ADD(TestArith::sqrt01);
		TEST_ADD(TestArith::sqrt02);
		TEST_ADD(TestArith::sqrt03);
		TEST_ADD(TestArith::sqrt04);
		TEST_ADD(TestArith::sqrt05);

		TEST_ADD(TestArith::sinh01);
		TEST_ADD(TestArith::sinh02);
		TEST_ADD(TestArith::sinh03);
		TEST_ADD(TestArith::sinh04);
		TEST_ADD(TestArith::sinh05);
		TEST_ADD(TestArith::sinh06);
		TEST_ADD(TestArith::sinh07);

		TEST_ADD(TestArith::cosh01);
		TEST_ADD(TestArith::cosh02);
		TEST_ADD(TestArith::cosh03);
		TEST_ADD(TestArith::cosh04);
		TEST_ADD(TestArith::cosh05);
		TEST_ADD(TestArith::cosh06);
		TEST_ADD(TestArith::cosh07);

		TEST_ADD(TestArith::atan2_01);
		TEST_ADD(TestArith::atan2_02);
		TEST_ADD(TestArith::atan2_03);
		TEST_ADD(TestArith::atan2_04);
		TEST_ADD(TestArith::atan2_05);
		TEST_ADD(TestArith::atan2_06);
		TEST_ADD(TestArith::atan2_07);
		TEST_ADD(TestArith::atan2_08);
		TEST_ADD(TestArith::atan2_09);
		TEST_ADD(TestArith::atan2_10);
		TEST_ADD(TestArith::atan2_11);
		TEST_ADD(TestArith::atan2_12);
		TEST_ADD(TestArith::atan2_13);
		TEST_ADD(TestArith::atan2_14);
		TEST_ADD(TestArith::atan2_15);

		TEST_ADD(TestArith::bwd_mul01);
		TEST_ADD(TestArith::bwd_mul02);
		TEST_ADD(TestArith::bwd_mul03);
		TEST_ADD(TestArith::bwd_mul04);
		TEST_ADD(TestArith::bwd_mul05);

		TEST_ADD(TestArith::bwd_mulVV01);
		TEST_ADD(TestArith::bwd_mulMV01);


		TEST_ADD(TestArith::bwd_div01);
		TEST_ADD(TestArith::bwd_div02);
		TEST_ADD(TestArith::bwd_div03);
		TEST_ADD(TestArith::bwd_div04);
		TEST_ADD(TestArith::bwd_div05);
		TEST_ADD(TestArith::bwd_div06);
		TEST_ADD(TestArith::bwd_div07);
		TEST_ADD(TestArith::bwd_div08);
		TEST_ADD(TestArith::bwd_div09);

		TEST_ADD(TestArith::bwd_maxmin01);
		TEST_ADD(TestArith::bwd_maxmin02);
		TEST_ADD(TestArith::bwd_maxmin03);
		TEST_ADD(TestArith::bwd_maxmin04);
		TEST_ADD(TestArith::bwd_maxmin05);

		TEST_ADD(TestArith::bwd_sqr01);
		TEST_ADD(TestArith::bwd_sqr02);
		TEST_ADD(TestArith::bwd_sqr03);
		TEST_ADD(TestArith::bwd_sqr04);
		TEST_ADD(TestArith::bwd_sqr05);
		TEST_ADD(TestArith::bwd_sqr06);
		TEST_ADD(TestArith::bwd_sqr07);

		TEST_ADD(TestArith::bwd_log01);
		TEST_ADD(TestArith::bwd_log02);
		TEST_ADD(TestArith::bwd_log03);
		TEST_ADD(TestArith::bwd_log04);
		TEST_ADD(TestArith::bwd_log05);
		TEST_ADD(TestArith::bwd_log06);
		TEST_ADD(TestArith::bwd_log07);
		TEST_ADD(TestArith::bwd_log08);

		TEST_ADD(TestArith::bwd_sin01);
		TEST_ADD(TestArith::bwd_sin02);
		TEST_ADD(TestArith::bwd_sin03);
		TEST_ADD(TestArith::bwd_sin04);
		TEST_ADD(TestArith::bwd_sin05);
		TEST_ADD(TestArith::bwd_sin06);
		TEST_ADD(TestArith::bwd_sin07);
		TEST_ADD(TestArith::bwd_sin08);
		TEST_ADD(TestArith::bwd_sin09);
		TEST_ADD(TestArith::bwd_sin10);
		TEST_ADD(TestArith::bwd_sin11);
		TEST_ADD(TestArith::bwd_sin12);
		TEST_ADD(TestArith::bwd_sin13);
		TEST_ADD(TestArith::bwd_sin14);
		TEST_ADD(TestArith::bwd_sin15);
		TEST_ADD(TestArith::bwd_sin16);
		TEST_ADD(TestArith::bwd_sin17);
		TEST_ADD(TestArith::bwd_sin18);
		TEST_ADD(TestArith::bwd_sin19);
		TEST_ADD(TestArith::bwd_sin20);
		TEST_ADD(TestArith::bwd_sin21);
		TEST_ADD(TestArith::bwd_sin22);
		TEST_ADD(TestArith::bwd_sin23);
		TEST_ADD(TestArith::bwd_sin24);

		TEST_ADD(TestArith::bwd_pow01);
		TEST_ADD(TestArith::bwd_pow02);
		TEST_ADD(TestArith::bwd_pow03);
		TEST_ADD(TestArith::bwd_pow04);
		TEST_ADD(TestArith::bwd_pow05);
		TEST_ADD(TestArith::bwd_pow06);
		TEST_ADD(TestArith::bwd_pow07);
		TEST_ADD(TestArith::bwd_pow08);
		TEST_ADD(TestArith::bwd_pow09);
		TEST_ADD(TestArith::bwd_pow10);
		TEST_ADD(TestArith::bwd_pow11);
		TEST_ADD(TestArith::bwd_pow12);
		TEST_ADD(TestArith::bwd_pow13);
		TEST_ADD(TestArith::bwd_pow14);
		TEST_ADD(TestArith::bwd_pow15);
		TEST_ADD(TestArith::bwd_pow16);
		TEST_ADD(TestArith::bwd_pow17);

		// ===== temporarily commented ===============
		TEST_ADD(TestArith::bwd_atan2_01);
		TEST_ADD(TestArith::bwd_atan2_02);
		TEST_ADD(TestArith::bwd_atan2_03);
		TEST_ADD(TestArith::bwd_atan2_04);
		TEST_ADD(TestArith::bwd_atan2_05);
		TEST_ADD(TestArith::bwd_atan2_06);
		TEST_ADD(TestArith::bwd_atan2_07);
		TEST_ADD(TestArith::bwd_atan2_08);
		TEST_ADD(TestArith::bwd_atan2_09); // commented waiting for an optimal contractor.
		TEST_ADD(TestArith::bwd_atan2_10);
		TEST_ADD(TestArith::bwd_atan2_issue134);

		TEST_ADD(TestArith::bwd_sqrt01);
		TEST_ADD(TestArith::bwd_sqrt02);
		TEST_ADD(TestArith::bwd_sqrt03);
		TEST_ADD(TestArith::bwd_sqrt04);
		TEST_ADD(TestArith::bwd_sqrt05);
		TEST_ADD(TestArith::bwd_sqrt06);
		TEST_ADD(TestArith::bwd_sqrt07);

		TEST_ADD(TestArith::bwd_atan01);
		TEST_ADD(TestArith::bwd_atan02);
		TEST_ADD(TestArith::bwd_atan03);
		TEST_ADD(TestArith::bwd_atan04);
		TEST_ADD(TestArith::bwd_atan05);
		TEST_ADD(TestArith::bwd_atan06);
		TEST_ADD(TestArith::bwd_atan07);
		TEST_ADD(TestArith::bwd_atan08);

		TEST_ADD(TestArith::bwd_add01);
		TEST_ADD(TestArith::bwd_add02);
		TEST_ADD(TestArith::bwd_add03);
		TEST_ADD(TestArith::bwd_add04);
		TEST_ADD(TestArith::bwd_add05);

		TEST_ADD(TestArith::bwd_sub01);
		TEST_ADD(TestArith::bwd_sub02);
		TEST_ADD(TestArith::bwd_sub03);
		TEST_ADD(TestArith::bwd_sub04);
		TEST_ADD(TestArith::bwd_sub05);

		TEST_ADD(TestArith::bwd_imod_01);
		TEST_ADD(TestArith::bwd_imod_02);
		TEST_ADD(TestArith::bwd_imod_03);
		TEST_ADD(TestArith::bwd_imod_04);
		TEST_ADD(TestArith::bwd_imod_05);
		TEST_ADD(TestArith::bwd_imod_06);
		TEST_ADD(TestArith::bwd_imod_07);
		TEST_ADD(TestArith::bwd_imod_08);
	}
private:

	/* test: operator&=(const Interval& x) */
	void minus01();
	void minus02();
	void minus03();
	void minus04();

	/* test:
	 * =======
	 *   operator+=(double d)
	 *   operator+=(const Interval& x)
	 *   operator+(const Interval& x, double d)
	 *   operator+(double d,const Interval& x)
	 *   operator+(const Interval& x1, const Interval& x2)
	 *   operator-=(double d)
	 *   operator-=(const Interval& x)
	 *   operator-(const Interval& x, double d)
	 *   operator-(double d,const Interval& x)
	 *   operator-(const Interval& x1, const Interval& x2)
	 */
	void add01();
	void add02();
	void add03();
	void add04();
	void add05();
	void add06();
	void add07();
	void add08();
	void add09();
	void add10();
	void add11();

	/* test:
	 * =======
	 *   operator*=(double d)
	 *   operator*=(const Interval& x)
	 *   operator*(const Interval& x, double d)
	 *   operator*(double d,const Interval& x)
	 *   operator*(const Interval& x1, const Interval& x2)
	 */
	void mul01();
	void mul02();
	void mul03();
	void mul04();
	void mul05();
	void mul06();
	void mul07();
	void mul08();
	void mul09();
	void mul10();
	void mul11();
	void mul12();
	void mul13();
	void mul14();
	void mul15();
	void mul16();
	void mul17();
	void mul18();
	void mul19();

	void mulMM01();

	/* test:
	 * =======
	 *   operator/=(double d)
	 *   operator/=(const Interval& x)
	 *   operator/(const Interval& x, double d)
	 *   operator/(double d,const Interval& x)
	 *   operator/(const Interval& x1, const Interval& x2)
	 */

	void div01();
	void div02();
	void div03();
	void div04();
	void div05();
	void div06();
	void div07();
	void div08();
	void div09();
	void div10();
	void div11();
	void div12();
	void div13();
	void div14();
	void div15();
	void div16();
	void div17();

	/* test:
	 * =========
	 *  div2_inter(const Interval& x, const Interval& y, Interval& out2)
	 *  div2_inter(const Interval& x, const Interval& y)
	 *  div2(const Interval& x, const Interval& y, Interval& out1, Interval& out2)
	 */
	void div2_01();
	void div2_02();
	void div2_03();
	void div2_04();
	void div2_05();
	void div2_06();
	void div2_07();
	void div2_08();
	void div2_09();
	void div2_10();
	void div2_11();
	void div2_12();
	void div2_13();

	void log01();
	void log02();
	void log03();
	void log04();
	void log05();
	void log06();

	/* test:
	 * sin
	 * cos
	 */
	void sin01();
	void sin02();
	void sin03();
	void sin04();
	void sin05();
	void sin06();
	void sin07();
	void sin08();
	void sin09();
	void sin10();
	void sin11();
	void sin12();
	void sin13();

	void tan01();
	void tan02();
	void tan03();
	void tan04();
	void tan05();
	void tan06();
	void tan07();

	void pow01();
	void pow02();
	void pow03();
	void pow04();
	void pow05();
	void pow06();
	void pow07();
	void pow08();
	void pow09();
	void pow10();
	void pow11();
	void pow12();
	void pow13();

	void root01();
	void root02();

	/* test: sqrt(const Interval& x); */
	void sqrt01();
	void sqrt02();
	void sqrt03();
	void sqrt04();
	void sqrt05();

	void sinh01();
	void sinh02();
	void sinh03();
	void sinh04();
	void sinh05();
	void sinh06();
	void sinh07();

	void cosh01();
	void cosh02();
	void cosh03();
	void cosh04();
	void cosh05();
	void cosh06();
	void cosh07();

	void atan2_01();
	void atan2_02();
	void atan2_03();
	void atan2_04();
	void atan2_05();
	void atan2_06();
	void atan2_07();
	void atan2_08();
	void atan2_09();
	void atan2_10();
	void atan2_11();
	void atan2_12();
	void atan2_13();
	void atan2_14();
	void atan2_15();

	/* test: bwd_mul */
	void bwd_mul01();
	void bwd_mul02();
	void bwd_mul03();
	void bwd_mul04();
	void bwd_mul05();

	void bwd_mulVV01();
	void bwd_mulMV01();

	/* test: bwd_div */
	void bwd_div01();
	void bwd_div02();
	void bwd_div03();
	void bwd_div04();
	void bwd_div05();
	void bwd_div06();
	void bwd_div07();
	void bwd_div08();
	void bwd_div09();

	void bwd_maxmin01();
	void bwd_maxmin02();
	void bwd_maxmin03();
	void bwd_maxmin04();
	void bwd_maxmin05();

	/* test: bwd_sqrt(const Interval& y, Interval& x) */
	void bwd_sqr01();
	void bwd_sqr02();
	void bwd_sqr03();
	void bwd_sqr04();
	void bwd_sqr05();
	void bwd_sqr06();
	void bwd_sqr07();

	void bwd_log01();
	void bwd_log02();
	void bwd_log03();
	void bwd_log04();
	void bwd_log05();
	void bwd_log06();
	void bwd_log07();
	void bwd_log08();

	/* test: bwd_sin & bwd_cos */
	void bwd_sin01();
	void bwd_sin02();
	void bwd_sin03();
	void bwd_sin04();
	void bwd_sin05();
	void bwd_sin06();
	void bwd_sin07();
	void bwd_sin08();
	void bwd_sin09();
	void bwd_sin10();
	void bwd_sin11();
	void bwd_sin12();
	void bwd_sin13();
	void bwd_sin14();
	void bwd_sin15();
	void bwd_sin16();
	void bwd_sin17();
	void bwd_sin18();
	void bwd_sin19();
	void bwd_sin20();
	void bwd_sin21();
	void bwd_sin22();
	void bwd_sin23();
	void bwd_sin24();

	void bwd_pow01();
	void bwd_pow02();
	void bwd_pow03();
	void bwd_pow04();
	void bwd_pow05();
	void bwd_pow06();
	void bwd_pow07();
	void bwd_pow08();
	void bwd_pow09();
	void bwd_pow10();
	void bwd_pow11();
	void bwd_pow12();
	void bwd_pow13();
	void bwd_pow14();
	void bwd_pow15();
	void bwd_pow16();
	void bwd_pow17();

	void bwd_atan2_01();
	void bwd_atan2_02();
	void bwd_atan2_03();
	void bwd_atan2_04();
	void bwd_atan2_05();
	void bwd_atan2_06();
	void bwd_atan2_07();
	void bwd_atan2_08();
	void bwd_atan2_09();
	void bwd_atan2_10();
	void bwd_atan2_issue134();

	void bwd_sqrt01();
	void bwd_sqrt02();
	void bwd_sqrt03();
	void bwd_sqrt04();
	void bwd_sqrt05();
	void bwd_sqrt06();
	void bwd_sqrt07();

	void bwd_atan01();
	void bwd_atan02();
	void bwd_atan03();
	void bwd_atan04();
	void bwd_atan05();
	void bwd_atan06();
	void bwd_atan07();
	void bwd_atan08();

	void bwd_add01();
	void bwd_add02();
	void bwd_add03();
	void bwd_add04();
	void bwd_add05();

	void bwd_sub01();
	void bwd_sub02();
	void bwd_sub03();
	void bwd_sub04();
	void bwd_sub05();

	void bwd_imod_01();
	void bwd_imod_02();
	void bwd_imod_03();
	void bwd_imod_04();
	void bwd_imod_05();
	void bwd_imod_06();
	void bwd_imod_07();
	void bwd_imod_08();


	void check_add_scal(const Interval& x, double z, const Interval& y_expected);
	void check_add(const Interval& x, const Interval& z, const Interval& y_expected);
	void check_mul_scal(const Interval& x, double z, const Interval& y_expected);
	void check_mul(const Interval& x, const Interval& z, const Interval& y_expected);
	void check_div_scal(const Interval& x, double z, const Interval& y_expected);
	void check_div(const Interval& x, const Interval& z, const Interval& y_expected);
	void check_div2(const Interval& x, const Interval& y, const Interval& out1, const Interval& out2);
	void check_sinh(const Interval& x);
	void check_cosh(const Interval& x);
	void check_trigo(const Interval& x, const Interval& y);

	void check_pow(const Interval& x, int p, const Interval& y_expected);
	bool checkbwd_mul(const Interval& y, const Interval& x1_before, const Interval& x2_before, const Interval& x1_after, const Interval& x2_after);
	void checkbwd_div(const Interval& y, const Interval& x1_before, const Interval& x2_before, const Interval& x1_after, const Interval& x2_after);
	void checkbwd_max(const Interval& z,  const Interval& x, const Interval& y, const Interval& x_expected, const Interval& y_expected);
	void checkbwd_trigo(const Interval& y, const Interval& xbefore, const Interval& xafter);
	void checkbwd_pow(const Interval& y, const Interval& xbefore, const Interval& xafter, int p);
	bool checkbwd_atan2(const Interval& a, const Interval& y_bef, const Interval& x_bef,
								const Interval& y_aft, const Interval& x_aft);
	bool checkbwd_atan(const Interval& y, const Interval& xbefore, const Interval& xafter);
	bool checkbwd_add(const Interval& y, const Interval& x1_before, const Interval& x2_before, const Interval& x1_after, const Interval& x2_after);
	bool checkbwd_sub(const Interval& y, const Interval& x1_before, const Interval& x2_before, const Interval& x1_after, const Interval& x2_after);
	bool checkbwd_imod(const double& period, const Interval& x_bef, const Interval& y_bef,
								const Interval& x_aft, const Interval& y_aft);

};

#endif // __TEST_ARITH__
