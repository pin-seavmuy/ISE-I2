// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#pragma once
#include <string>
#include <string_view>

namespace clubhub {
    // Put your actual team name here
    inline constexpr std::string_view kTeamName = "I2-ISE";

    // Formats and returns the startup banner ending in newline
    [[nodiscard]] std::string banner(std::string_view teamName);
}
