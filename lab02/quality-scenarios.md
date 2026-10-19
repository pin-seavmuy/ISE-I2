# Lab-02 · Quality Attribute Scenarios for ITC Club Hub
Version 1.0 · 2026-10-19 · Reviewed by (Scrum Master): Sokha Pich

---

## QAS-01 · Availability · written by Chan Dara
| Part | Content |
| :--- | :--- |
| **Source** | Students (up to 500 concurrent users). |
| **Stimulus** | High traffic spike when event registration opens on Friday at 18:00. |
| **Environment** | Normal peak load, cloud-hosted server. |
| **Artifact** | `RegistrationService` and database layer. |
| **Response** | System handles incoming traffic, queues registrations, and prevents crashes. |
| **Response Measure** | 0 unhandled server crashes; system uptime $\ge 99.9\%$; server returns valid HTTP response within $\le 2\text{ seconds}$. |

---

## QAS-02 · Performance (Door Check-In) · written by Sokha Pich
| Part | Content |
| :--- | :--- |
| **Source** | Event organiser scanning participant QR code. |
| **Stimulus** | 200 participants arriving at Hall A entrance within 10 minutes (1 arrival every 3 seconds). |
| **Environment** | Flaky/congested venue Wi-Fi or weak 3G mobile data at door. |
| **Artifact** | PWA scanner frontend and `RegistrationService::checkIn`. |
| **Response** | Validates ticket against local cache, displays green confirmation banner, and queues record. |
| **Response Measure** | On-screen check-in confirmation renders in $\le 500\text{ ms}$; exactly 0 check-in records lost. |

---

## QAS-03 · Usability (Event Registration) · written by Bopha Keo
| Part | Content |
| :--- | :--- |
| **Source** | First-year ITC student using the app for the first time. |
| **Stimulus** | Searches for and registers for an upcoming "Robotics Workshop". |
| **Environment** | Handheld smartphone running Android/iOS on campus Wi-Fi. |
| **Artifact** | PWA Event Browse & Registration UI. |
| **Response** | System presents clear event search, visible seat counter, and 1-tap registration. |
| **Response Measure** | Student completes registration in $\le 4\text{ screen taps}$ and under $30\text{ seconds}$ without needing a tutorial or help page. |

---

## QAS-04 · Security (Data Protection & Identity Spoofing) · written by Minea Heng
| Part | Content |
| :--- | :--- |
| **Source** | Malicious student attempting to forge registration for another user. |
| **Stimulus** | Sends forged HTTP POST requests using another student's ID to register or view their phone number. |
| **Environment** | Public untrusted internet connection. |
| **Artifact** | API Authentication Gateway and personal data fields (`StudentId`, `phone`, `email`). |
| **Response** | System validates session token against ITC directory, rejects unauthorized ID, and logs security audit alert. |
| **Response Measure** | 0 unauthorized profile exposures; 100% of forged requests rejected with HTTP 403 Forbidden. |

---

## QAS-05 · Modifiability (Adding Waiting List in Sprint 2) · written by Ratanak Lim
| Part | Content |
| :--- | :--- |
| **Source** | Product Owner introducing Change Request CR-14 (Waiting List). |
| **Stimulus** | Developers must add automatic waitlisting when event capacity reaches 100%. |
| **Environment** | Standard development sprint. |
| **Artifact** | `RegistrationService` C++ class and `data/registrations.csv`. |
| **Response** | Developers extend the domain model by adding `RegistrationStatus::Waitlisted` without refactoring existing `Event` logic. |
| **Response Measure** | Feature implemented in $\le 1\text{ developer-day}$; modifies $\le 3\text{ files}$; retains $100\%$ backward compatibility with existing CSV files. |

---

## QAS-06 · Portability (Cross-Platform Compilation) · written by Chan Dara
| Part | Content |
| :--- | :--- |
| **Source** | DevOps Engineer / Developer running build scripts. |
| **Stimulus** | Compiling and executing test suite across diverse team operating systems. |
| **Environment** | Windows 11 (Visual Studio 2022 / MSVC) and Linux Ubuntu 24.04 (GCC 13 / Clang 17). |
| **Artifact** | `CMakeLists.txt` and C++20 core code. |
| **Response** | CMake generates native build files and compiles cleanly without warnings. |
| **Response Measure** | 0 compiler warnings at `/W4` (MSVC) and `-Wall -Wextra -Wpedantic` (GCC); 100% test pass rate on both OS platforms. |

---

## Priority Table
| Scenario | Quality Attribute | Business Importance | Technical Risk | User Group Protected | Satisfy First? |
| :---: | :--- | :---: | :---: | :--- | :---: |
| **QAS-01** | Availability | **High** | **High** | Students | **YES (★ 1st)** |
| **QAS-02** | Performance (Door) | **High** | **High** | Organisers & Attendees | **YES (★ 2nd)** |
| **QAS-03** | Usability | Medium | Low | Students | No |
| **QAS-04** | Security | High | Medium | All Students | No |
| **QAS-05** | Modifiability | Medium | Medium | Developers | No |
| **QAS-06** | Portability | Medium | Low | Team & DevOps | No |

> **Architectural Focus:** The architecture must prioritize **QAS-01 (Availability under Friday peak)** and **QAS-02 (Door performance with offline tolerance)** before all other qualities.
