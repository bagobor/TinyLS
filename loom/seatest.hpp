#ifndef SEATEST_HPP
#define SEATEST_HPP

#include "loom/common/core/performance.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <seatest.h>


/** Totally sweet macros, added by BJG **/
#define SEATEST_TEST(testName) \
   void __cdecl test_impl_##testName(void)

#define SEATEST_FIXTURE(fixtureName) \
   static void __cdecl test_fixture_inner_##fixtureName(); \
   void __cdecl test_fixture_##fixtureName(void) { \
      test_fixture_start(); tmEnter(gTelemetryContext, TMZF_NONE, (const char *)#fixtureName); \
      test_fixture_inner_##fixtureName(); \
      tmLeave(gTelemetryContext); test_fixture_end(); }; \
   static void __cdecl test_fixture_inner_##fixtureName()

#define SEATEST_FIXTURE_ENTRY(testName) \
   tmEnter(gTelemetryContext, TMZF_NONE, (const char *)#testName); \
   void __cdecl test_impl_##testName(void); \
   run_test(test_impl_##testName); \
   tmLeave(gTelemetryContext); \
   performance_tick();

#define SEATEST_SUITE(suiteName) void __cdecl test_suite_##suiteName()
#define SEATEST_SUITE_ENTRY(fixtureName) extern void __cdecl test_fixture_##fixtureName(); test_fixture_##fixtureName()
    
#ifdef __cplusplus
};
#endif

#endif