# Requirements (Classified) · ITC Club Hub
Version 1.0 · 2026-11-14 · Team: I2-ISE  
Standard: ISO/IEC/IEEE 29148:2018 & ISO/IEC 25010 Quality Model

---

## 1. User Requirements (UR)

| UR ID | User Requirement Statement | Source Needs | Type |
| :--- | :--- | :---: | :---: |
| **UR-01** | A student can browse upcoming events published across all campus clubs in one consolidated calendar. | N-01 | Functional |
| **UR-02** | A student can register for an open event with their student credentials in under 60 seconds. | N-02, N-03 | Functional |
| **UR-03** | A student can cancel their confirmed registration before the deadline so their seat is released for others. | N-04 | Functional |
| **UR-04** | A student can opt in to receive event reminder alerts 24 hours prior to the event. | N-05 | Functional |
| **UR-05** | A club leader can create and publish events with location, date/time, description, and strict capacity. | N-06, N-07 | Functional |
| **UR-06** | An event organiser can verify tickets and check in attendees quickly at the room entrance. | N-10, N-13 | Functional |
| **UR-07** | An event organiser can conduct door check-in even when campus Wi-Fi or cellular network drops. | N-11 | Non-Functional |
| **UR-08** | An administrator can review, approve, or reject new student clubs. | N-14 | Functional |
| **UR-09** | An administrator can inspect monthly aggregated participation metrics across all clubs for funding reviews. | N-15 | Functional |
| **UR-10** | A student can trust that their personal data is minimized, masked in logs, and kept private from third parties. | N-16 | Non-Functional |

---

## 2. System Functional Requirements (FR)
*Format: "The system shall ..." — Incorporating all 5 Core Business Rules.*

| FR ID | System Requirement Statement | Refines | Business Rule Enforced |
| :--- | :--- | :---: | :--- |
| **FR-01** | The system shall display upcoming events sorted chronologically by start time, filtering out past events. | UR-01 | Rule: Events in the past cannot be registered for. |
| **FR-02** | The system shall record a student registration and increment the event's current registration count. | UR-02 | Core Registration |
| **FR-03** | The system shall reject registration if the event has reached its maximum defined capacity. | UR-02, UR-05 | **Rule 1: Capacity cannot be exceeded.** |
| **FR-04** | The system shall reject registration if the student is already registered for that same event. | UR-02 | **Rule 2: A student cannot register twice for the same event.** |
| **FR-05** | The system shall allow registration cancellation and release the seat if requested $\ge 24$ hours before event start. | UR-03 | **Rule 3: Cancellation closes strictly 24 hours before event start.** |
| **FR-06** | The system shall reject cancellation requests submitted $< 24$ hours before event start time. | UR-03 | **Rule 3: Cancellation closes strictly 24 hours before event start.** |
| **FR-07** | The system shall reject registration attempts for events whose start time is in the past. | UR-01, UR-02 | **Rule 4: Events in the past cannot be registered for.** |
| **FR-08** | The system shall permit event creation and publication only by clubs whose status is `Approved`. | UR-05, UR-08 | **Rule 5: Only approved clubs can publish events.** |
| **FR-09** | The system shall record attendance upon ticket validation and transition status to `CheckedIn`. | UR-06 | Check-In Flow |
| **FR-10** | The system shall detect and reject duplicate check-in attempts using an already redeemed ticket ID. | UR-06 | Anti-Passback Fraud Rule |
| **FR-11** | The system shall queue check-in transactions locally when offline and synchronize them when online. | UR-07 | Offline Idempotent Queue |
| **FR-12** | The system shall generate monthly activity reports with aggregated headcounts per club while purging individual student IDs. | UR-09, UR-10 | Privacy & Minimization |
| **FR-13** | The system shall allow students to opt in or withdraw consent for email/SMS reminders at any time. | UR-04, UR-10 | Consent Management |

---

## 3. System Non-Functional Requirements (NFR)
*Classified according to ISO/IEC 25010 Quality Model & Lab-02/Lab-03 Deliverables.*

| NFR ID | Requirement Statement & Target Metric | Refines | ISO 25010 Category | Source Reference |
| :--- | :--- | :---: | :--- | :--- |
| **NFR-01** | The system shall process door check-ins in **$< 1.0$ second** for $\ge 95\%$ of scans, processing 100 students in $< 10$ minutes. | UR-06 | Performance Efficiency (Time Behaviour) | Lab-02 QAS-01 |
| **NFR-02** | A first-time student shall be able to complete event registration in **$< 60$ seconds** without prior training. | UR-02 | Usability (Learnability & Operability) | Lab-02 QAS-02 |
| **NFR-03** | The system shall continue local check-in operations during zero-network conditions with $0\%$ lost check-ins. | UR-07 | Reliability (Fault Tolerance & Availability) | Lab-02 QAS-03 |
| **NFR-04** | If an abrupt server or power crash occurs while saving, the system shall recover with zero corrupted registrations. | UR-02 | Reliability (Recoverability) | Lab-02 QAS-04 |
| **NFR-05** | The system shall mask student IDs in console outputs and logs (`Student{id=e2******7}`), never outputting full names or emails. | UR-10 | Security (Confidentiality & Privacy) | Lab-03 Privacy Notice |
| **NFR-06** | Console output shall support `NO_COLOR` and avoid relying on color alone to convey status (WCAG 2.2 AA). | UR-01 | Accessibility (Perceivability) | Lab-03 CLI Rules |

---

## 4. Rejected or Deferred Needs

| Raw Need | Proposed Feature | Reason for Rejection / Deferral |
| :--- | :--- | :--- |
| **N-Deferred-01** | Automated Waiting List Promotion | **Deferred to Sprint 2 (Should Feature):** For Sprint 1, when a seat is cancelled, it is immediately released to the general pool to keep core business logic lean. |
| **N-Deferred-02** | In-App Direct Messaging / Chat | **Rejected (Out of Scope):** ITC clubs already actively use Telegram channels. Building a custom chat client introduces high security overhead without adding product value. |
| **N-Deferred-03** | Commercial Event Ticketing / Online Payments | **Rejected (Scope & Legal):** All ITC student club activities are free or campus-funded. Adding payment gateways requires banking compliance not needed for the semester. |