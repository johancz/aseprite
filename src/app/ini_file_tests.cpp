// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#include "tests/test.h"

#include "app/ini_file.h"
#include "base/fs.h"

using namespace app;

TEST(IniFile, Basic)
{
  if (base::is_file("_test.ini"))
    base::delete_file("_test.ini");

  set_config_file("_test.ini");

  EXPECT_EQ(false, get_config_bool("A", "a", false));
  EXPECT_EQ(true, get_config_bool("A", "b", true));
  EXPECT_EQ(0, get_config_bool("B", "a", 0));
  EXPECT_EQ(1, get_config_bool("B", "b", 1));

  set_config_bool("A", "a", true);
  set_config_bool("A", "b", false);
  set_config_int("B", "a", 2);
  set_config_int("B", "b", 3);

  EXPECT_EQ(true, get_config_bool("A", "a", false));
  EXPECT_EQ(false, get_config_bool("A", "b", true));
  EXPECT_EQ(2, get_config_int("B", "a", 0));
  EXPECT_EQ(3, get_config_int("B", "b", 1));
}

TEST(IniFile, PushPop)
{
  if (base::is_file("_a.ini")) base::delete_file("_a.ini");
  if (base::is_file("_b.ini")) base::delete_file("_b.ini");

  set_config_file("_a.ini");
  set_config_int("A", "a", 32);

  push_config_state();
  set_config_file("_b.ini");
  set_config_int("A", "a", 64);
  EXPECT_EQ(64, get_config_int("A", "a", 0));
  pop_config_state();

  EXPECT_EQ(32, get_config_int("A", "a", 0));
}
