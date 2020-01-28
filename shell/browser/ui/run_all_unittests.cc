// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/bind.h"
#include "base/test/launcher/unit_test_launcher.h"
#include "base/test/test_suite.h"
#include "build/build_config.h"

int main(int argc, char** argv) {
#if defined(OS_WIN)
  // Eagerly load advapi32.dll since tests need it.
  CHECK(::LoadLibrary(L"advapi32.dll"));
#endif  // defined(OS_WIN)
  base::TestSuite test_suite(argc, argv);
  return base::LaunchUnitTests(
      argc, argv,
      base::BindOnce(&base::TestSuite::Run, base::Unretained(&test_suite)));
}
