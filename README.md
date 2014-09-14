bandit
======
[![Build Status](https://travis-ci.org/joakimkarlsson/bandit.png)](https://travis-ci.org/joakimkarlsson/bandit)

Human friendly unit testing for C++11

Bandit is a framework for C++11 that wants to make working with unit tests a pleasant
experience.

For more information, go to [the bandit website](http://banditcpp.org).

Bandit is released under the [MIT license](LICENSE.md)

#An example

This is a complete test application written in bandit:


    #include <bandit/bandit.h>
    using namespace bandit;

    // Tell bandit there are tests here.
    go_bandit([](){

        // We are describing how a fuzzbox works.
        describe("fuzzbox:", [](){
          guitar_ptr guitar;
          fuzzbox_ptr fuzzbox;

          // Make sure each test has a fresh setup with
          // a guitar with a fuzzbox connected to it.
          before_each([&](){
            guitar = guitar_ptr(new struct guitar());
            fuzzbox = fuzzbox_ptr(new struct fuzzbox());
            guitar->add_effect(*fuzzbox);
          });

          it("starts in clean mode", [&](){
            AssertThat(guitar->sound(), Equals(sounds::clean));
          });
         });

        // Describe what happens when we turn on the fuzzbox.
        describe("in distorted mode", [&](){

          // Turn on the fuzzbox.
          before_each([&](){
            fuzzbox->flip();
          });

          it("sounds distorted", [&](){
            AssertThat(guitar->sound(), Equals(sounds::distorted));
          });
        });
    });

    int main(int argc, char* argv[])
    {
      // Run the tests.
      return bandit::run(argc, argv);
    }


# Biicode block

The source shared through this biicode block is released under exactly the same license as the original project, 
see the `license.md` file for more info.

In fact, this biicode block only acts as a mirror of the original github-hosted project, with a few changes:

 - Bandit is a header-only library, so no additional tools and configuration are required to use it. However, the 
   original github project had some install scripts and specs used for testing. This biicode block doesn't include
   them.

 - For an easy integration with biicode dependency management, this block defines a link to the `bandit/bandit.h` 
   umbrella header, located at the top of the block directory. This allows biicode users to use bandit with just a 
   `#include "manu343726/bandit/bandit.h"` instead of `#include "manu343726/bandit/bandit/bandit.h"`.
