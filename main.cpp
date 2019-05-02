#include <iostream>
#include "methods/CheckLibary.h"

int main() {
   CheckLibary checker;
   Program program("IOIOIOIOKKIKIVOIVICVIOIONIONIOCVIONIOIIOKIIOOIIONOVIOIIOIIOOIIONOIIONOOIVIVIOONNNNNNNNONONNNVIONIIICVIONIOIOIIOIIOOKN");
   program.setTokenSet(program.getSourseCode());
   Program program1("IOIOIOIOKKIKIVOIVIVIOIONCIONCVIONIOIIOKIIONOOIIOVIOIIOIIOOIIONOIIONOOIIOVIVIOONNNNNNNNONONNNVIONIIICVIONIOIOIIOIIOOKN");
   program1.setTokenSet(program1.getSourseCode());
   int result = checker.getLevenstainResult(program,program1);
   std::cout<<result;
    return 0;
}