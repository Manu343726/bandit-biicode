
#include "manu343726/bandit/bandit.h"

using namespace bandit;

/*
 * We are writting a complex-number library, and we want to test if our implementation works correctly.
 * I.e. it adds and substracts two complex numbers correctly
 */

 #include <complex>

 typedef std::complex<double> MyAwesomeComplex;


 go_bandit([]()
 {
 	/*
 	 * With a describe() call we explain to bandit what we are going to test
 	 */
 	describe("Testing simple arithmetic between complex numbers",[]()
 	{
 		/*
 		 * You can declare "global" variables to be shared between tests. These
 		 * variables should be captured by the lambdas of the tests, note the by-value
 		 * capture specifiers bellow (=).
 		 *
 		 * If you want to reset a variable before each test, you can use the 
 		 * before_each() function.
 		 */ 
 		MyAwesomeComplex a{1.0,0.0} , b{0.0,1.0} , c{1.0,1.0};

 		/*
 		 * Each it() call represents a test, in the form "The thing does this correctly"
 		 */
 		it("adds correctly",[=]()
 		{
 			AssertThat( a + b , Is().EqualTo(c));
 		});

 		it("substracts correctly",[=]()
 		{
			AssertThat( c - b , Is().EqualTo(a));
 		});
 	});

 	describe("Some other features",[]()
 	{
 		it("normmalizes numbers correctly",[]()
 		{
 			MyAwesomeComplex a{2.0 , 3.0};

 			auto normalize = [](const MyAwesomeComplex& c)
 			{
 				return c / std::sqrt(std::norm(c));
 			};


 			/*
 			 * Bandit uses the snowhouse assertion framework (https://github.com/joakimkarlsson/snowhouse) to write tests.
 			 * Snowhouse uses fluent interfaces to write conditions in a simple and declarative way:
 			 */

 			AssertThat(normalize(a).real() , Is().Not().LessThan(0.0).And().Not().GreaterThan(1.0));
 			AssertThat(normalize(a).imag() , Is().Not().LessThan(0.0).And().Not().GreaterThan(1.0));
 		});
 	});
 });

 int main(int argc, char* argv[])
 {
 	bandit::run(argc,argv);
 }