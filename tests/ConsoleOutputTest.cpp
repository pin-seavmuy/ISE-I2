// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"
#include <gtest/gtest.h>

using namespace clubhub;

// Test 1: Status is completely readable without color
TEST(ConsoleOutput, ReadableWithoutColour) {
    std::string out = formatStatus(RegistrationStatus::Registered, false);
    EXPECT_EQ(out, "[REGISTERED]");
    EXPECT_EQ(out.find("\033"), std::string::npos); // No escape characters
}

// Test 2: Coloured version still contains the full text label
TEST(ConsoleOutput, ColouredVersionContainsWord) {
    std::string out = formatStatus(RegistrationStatus::CheckedIn, true);
    // Must contain the text label so color-blind users and screen readers still get it
    EXPECT_NE(out.find("[CHECKED_IN]"), std::string::npos);
    EXPECT_NE(out.find("\033[32m"), std::string::npos); // Has color code
}

// Test 3: Actionable error message includes "Next step:"
TEST(ConsoleOutput, ErrorMessageContainsNextStep) {
    std::string err = formatError(
        "Registration closed",
        "Capacity (50/50) reached",
        "Run 'clubhub waitlist 101' to join the waiting list"
    );
    EXPECT_NE(err.find("Error: Registration closed"), std::string::npos);
    EXPECT_NE(err.find("Why: Capacity (50/50) reached"), std::string::npos);
    EXPECT_NE(err.find("Next step: Run 'clubhub waitlist 101'"), std::string::npos);
}
