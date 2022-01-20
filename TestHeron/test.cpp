#include "pch.h"

// Google test documentation
// Code : https://github.com/google/googletest
// User Guide : https://google.github.io/googletest/
// Cheatsheet sur les macros Google Test: https://qiangbo-workspace.oss-cn-shanghai.aliyuncs.com/2018-12-05-gtest-and-coverage/PlainGoogleQuickTestReferenceGuide1.pdf

#include "../Heron/heron.h"

TEST(TestHeron, Rectangle) {
  EXPECT_EQ(aire_triangle_heron(3.0, 4.0,5.0), 6);
}

TEST(TestHeron, Pointu) {
	EXPECT_EQ(aire_triangle_heron(3.0E100, 4.0, 3.0E100), 6E100);
}