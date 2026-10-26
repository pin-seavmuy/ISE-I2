// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"
#include <cstdlib>

namespace clubhub {

    std::string_view statusLabel(RegistrationStatus s) {
        switch (s) {
            case RegistrationStatus::Registered: return "[REGISTERED]";
            case RegistrationStatus::Cancelled:  return "[CANCELLED]";
            case RegistrationStatus::CheckedIn:  return "[CHECKED_IN]";
            case RegistrationStatus::Waitlisted: return "[WAITLISTED]";
        }
        return "[UNKNOWN]";
    }

    bool colourEnabled(bool noColorFlag) {
        if (noColorFlag) return false;
        // Check if NO_COLOR environment variable is set
        const char* envNoColor = std::getenv("NO_COLOR");
        if (envNoColor != nullptr && envNoColor[0] != '\0') {
            return false;
        }
        return true;
    }

    std::string formatStatus(RegistrationStatus s, bool colour) {
        std::string_view label = statusLabel(s);
        if (!colour) {
            return std::string(label);
        }

        // ANSI colors: Green for CheckedIn, Blue for Registered, Yellow for Waitlisted, Red for Cancelled
        std::string code;
        switch (s) {
            case RegistrationStatus::CheckedIn:  code = "\033[32m"; break; // Green
            case RegistrationStatus::Registered: code = "\033[34m"; break; // Blue
            case RegistrationStatus::Waitlisted: code = "\033[33m"; break; // Yellow
            case RegistrationStatus::Cancelled:  code = "\033[31m"; break; // Red
        }
        return code + std::string(label) + "\033[0m";
    }

    std::string formatError(std::string_view what, std::string_view why, std::string_view next) {
        std::string err;
        err.reserve(what.size() + why.size() + next.size() + 35);
        err += "Error: ";
        err += what;
        err += ". Why: ";
        err += why;
        err += ". Next step: ";
        err += next;
        return err;
    }

} // namespace clubhub
