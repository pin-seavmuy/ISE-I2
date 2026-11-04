# Make-or-Reuse Inventory · Team I2-ISE
Version 1.0 · 2026-11-04 · Lead: Developer & Product Owner

---

## 1. Technical Needs & Make-or-Reuse Decisions

| Need / Capability | Candidate Options | Decision | Reason & Justification | Licence | Pinned Version / Tag | Last Release Date |
| :--- | :--- | :---: | :--- | :---: | :---: | :---: |
| **1. Unit Testing** | GoogleTest, Catch2, doctest | **Reuse** | Industry standard, powerful assertion macros, seamlessly integrates with CMake `ctest`. | BSD-3-Clause | `v1.17.0` | 2024-10 |
| **2. CSV File Storage** | rapidcsv, fast-cpp-csv-parser, hand-rolled parser | **Reuse** | Header-only, zero external dependencies, robust column/row indexing, handles quoted commas cleanly. | BSD-3-Clause | `v8.84` | 2024-05 |
| **3. Date & Time Validation** | C++20 `<chrono>`, HowardHinnant/date | **Reuse (STL)** | Modern C++20 STL provides native calendar and timezone support (`std::chrono::sys_seconds`, `std::chrono::year_month_day`); no external library needed. | ISO C++ Standard | C++20 STL | Standard |
| **4. Command-Line Parser** | CLI11, cxxopts, hand-rolled `argc/argv` | **Reuse** | `CLI11` is header-only, provides built-in help screens, subcommands (`list-events`, `check-in`), and type validation. | BSD-3-Clause | `v2.4.2` | 2024-06 |
| **5. Core Business Rules** | Hand-rolled domain logic | **Build** | Core university business logic (24-hour cancellation rule, room capacity invariants, club status check) is unique to ITC Club Hub and must be custom built. | MIT (Our repo) | Internal | In Development |
| **6. Email / SMS Reminders** | libcurl + Twilio API, local mock | **Defer** | Physical SMS/Email sending is out of scope for the C++ CLI core; defer to Sprint 2 / mobile web phase; use simulated terminal logs for now. | n/a | Deferred | Deferred |
| **7. Activity Reporting** | Custom C++ aggregator, SQLite | **Build** | Simple monthly aggregation (counting attendance by club) is easily achieved with standard STL algorithms (`std::unordered_map`); database is unnecessary overhead. | MIT (Our repo) | Internal | In Development |
| **8. Structured Logging** | spdlog, basic `std::cout` helper | **Reuse** | `spdlog` provides fast, structured logging with log levels (INFO, WARN, ERROR) and integrates cleanly with CMake. | MIT | `v1.14.1` | 2024-04 |

---

## 2. Licence Compatibility Check

- **Our Project Licence (from Lab-03):** MIT Licence.
- **Third-Party Licences Reused:**
  - `GoogleTest`: BSD-3-Clause &rarr; **Compatible with MIT** (Permissive; requires retaining original copyright notice).
  - `rapidcsv`: BSD-3-Clause &rarr; **Compatible with MIT** (Permissive; header-only; no copyleft restrictions).
  - `CLI11`: BSD-3-Clause &rarr; **Compatible with MIT**.
  - `spdlog`: MIT Licence &rarr; **100% Compatible**.

👉 **Conclusion:** Zero copyleft (GPL) obligations. All dependencies are permissive and safely compatible with our MIT repository.

---

## 3. Verification of First Reused Dependency (`rapidcsv`)

### CTest Execution Output:
```text
Test project C:/Users/ASUS/ISE-I2/build
    Start 1: CsvSmokeTest.ReadsEventTitlesAndCapacities
1/1 Test #1: CsvSmokeTest.ReadsEventTitlesAndCapacities ...   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1
Total Test time (real) =   0.02 sec
```