# User Stories & Acceptance Scenarios · ITC Club Hub
Version 1.0 · 2026-11-14 · Team: I2-ISE  
Standard: Agile User Stories & Gherkin BDD (Given-When-Then)

---

## 1. User Stories Overview

| Story ID | Title | Role | Priority | Points | Source FR |
| :--- | :--- | :--- | :---: | :---: | :---: |
| **US-01** | Register New Club | Club Leader | Must | 3 | FR-08 |
| **US-02** | Approve or Reject Club | Administrator | Must | 3 | FR-08 |
| **US-03** | Publish an Event | Club Leader | Must | 5 | FR-01, FR-08 |
| **US-04** | Browse Upcoming Events | Student | Must | 3 | FR-01, FR-07 |
| **US-05** | Register for an Open Event | Student | Must | 5 | FR-02, FR-03, FR-04 |
| **US-06** | Reject Duplicate Registration | Student | Must | 2 | FR-04 |
| **US-07** | Reject Over-Capacity Registration | Student | Must | 3 | FR-03 |
| **US-08** | Cancel Registration Before Deadline | Student | Must | 3 | FR-05 |
| **US-09** | Reject Late Cancellation | Student | Must | 2 | FR-06 |
| **US-10** | Opt-In for Reminder Alerts | Student | Should | 2 | FR-13 |
| **US-11** | Withdraw Reminder Consent | Student | Should | 1 | FR-13 |
| **US-12** | Fast Door Check-In | Organiser | Must | 5 | FR-09, FR-10 |
| **US-13** | Offline Door Check-In Queue | Organiser | Must | 5 | FR-11 |
| **US-14** | View Live Door Headcount | Organiser | Should | 2 | FR-09 |
| **US-15** | Generate Monthly Attendance Report | Administrator | Must | 5 | FR-12 |
| **US-16** | View Masked Roster for Event | Club Leader | Should | 3 | FR-12 |

---

## 2. Detailed Stories & Gherkin Acceptance Scenarios

---

### US-01: Register New Club
**As a** club leader,  
**I want** to register my new club with a name, description, and founding leader ID,  
**So that** it can be officially recognized and allowed to publish events after approval.  
*Priority:* Must · *Source:* FR-08 · *Size:* 3 pts

```gherkin
Scenario: Successful club submission
  Given no club named "Robotics Club" exists in the registry
  When the club leader submits registration for "Robotics Club" with leader ID "e20220001"
  Then the club is recorded with status "Pending"
  And the administrator can view "Robotics Club" in the approval queue

Scenario: Reject duplicate club name
  Given an active or pending club named "Robotics Club" already exists
  When a user attempts to register a new club with name "Robotics Club"
  Then the system shall reject the registration with an error stating "Club name already taken"
```

---

### US-02: Approve or Reject Club
**As a** Student Affairs administrator,  
**I want** to review pending club applications and approve or reject them,  
**So that** only vetted student organizations represent the university.  
*Priority:* Must · *Source:* FR-08 · *Size:* 3 pts

```gherkin
Scenario: Administrator approves a pending club
  Given a club "Robotics Club" has status "Pending"
  When the administrator approves the club
  Then the club status transitions to "Approved"
  And the club leader gains permission to publish events

Scenario: Administrator rejects a club with feedback
  Given a club "Spam Club" has status "Pending"
  When the administrator rejects the club with reason "Incomplete charter"
  Then the club status transitions to "Rejected"
  And the club cannot publish events
```

---

### US-03: Publish an Event
**As an** approved club leader,  
**I want** to publish an event with a title, future date/time, room location, and max capacity,  
**So that** students across campus can discover and join our activity.  
*Priority:* Must · *Source:* FR-01, FR-08 · *Size:* 5 pts

```gherkin
Scenario: Successfully publish valid event
  Given my club "Robotics Club" has status "Approved"
  When I publish event "Arduino 101" starting at "2026-11-25 14:00" in room "Lab F-301" with capacity 30
  Then the event is saved with ID "E001" and status "Open"
  And it appears in the public event list

Scenario: Reject event publication by unapproved club (Business Rule 5)
  Given my club "Coding Ninjas" has status "Pending"
  When I attempt to publish an event "Web Dev Night"
  Then the system rejects the event with error "Only approved clubs can publish events"
```

---

### US-04: Browse Upcoming Events
**As a** student,  
**I want** to view all upcoming campus events in chronological order,  
**So that** I can easily find workshops that fit my academic schedule.  
*Priority:* Must · *Source:* FR-01, FR-07 · *Size:* 3 pts

```gherkin
Scenario: View sorted upcoming events
  Given event "E001" starts on "2026-11-20 14:00" and event "E002" starts on "2026-11-18 10:00"
  And today's system date is "2026-11-15 08:00"
  When I request the upcoming event list
  Then event "E002" is listed before event "E001"
  And both show title, location, capacity, and current open seats

Scenario: Hide past events from the active list (Business Rule 4)
  Given event "E099" took place on "2026-10-10 14:00"
  And today's system date is "2026-11-15 08:00"
  When I request the upcoming event list
  Then event "E099" is not displayed in the active list
```

---

### US-05: Register for an Open Event
**As a** student,  
**I want** to register for an event using my student ID,  
**So that** I reserve a guaranteed seat and receive a confirmation ticket.  
*Priority:* Must · *Source:* FR-02, FR-03, FR-04 · *Size:* 5 pts

```gherkin
Scenario: Successful registration with available seats
  Given event "E001" has max capacity 30 and currently has 10 registrations
  And student "e20220001" is not registered for "E001"
  When student "e20220001" registers for "E001"
  Then the registration status is confirmed as "Registered"
  And the event's registration count becomes 11
  And a ticket ID "TICK-E001-011" is issued
```

---

### US-06: Reject Duplicate Registration (Business Rule 2)
**As an** event organizer,  
**I want** the system to block a student from registering twice for the same event,  
**So that** ticket hoarding is prevented and seats remain available for others.  
*Priority:* Must · *Source:* FR-04 · *Size:* 2 pts

```gherkin
Scenario: Reject duplicate registration attempt
  Given student "e20220001" is already registered for event "E001"
  When student "e20220001" attempts to register for "E001" again
  Then the system rejects the registration
  And displays "Error: student e2******1 is already registered"
  And total registrations for "E001" remain unchanged
```

---

### US-07: Reject Over-Capacity Registration (Business Rule 1)
**As a** club leader,  
**I want** registration to close automatically when maximum capacity is reached,  
**So that** the room does not overflow beyond safety limits.  
*Priority:* Must · *Source:* FR-03 · *Size:* 3 pts

```gherkin
Scenario: Reject registration when room is full
  Given event "E001" has max capacity 25 and 25 registered students
  When student "e20220099" attempts to register for "E001"
  Then the registration request is rejected
  And displays "Error: event E001 is full (25 of 25 seats taken)"
```

---

### US-08: Cancel Registration Before Deadline (Business Rule 3: Allowed Side)
**As a** student,  
**I want** to cancel my registration at least 24 hours before the event,  
**So that** I release my seat for a fellow classmate without penalty.  
*Priority:* Must · *Source:* FR-05 · *Size:* 3 pts

```gherkin
Scenario: Cancellation exactly 24 hours before event is allowed
  Given event "E001" starts on "2026-11-20 14:00"
  And student "e20220001" holds a confirmed ticket for "E001"
  And the current system time is "2026-11-19 14:00" (exactly 24 hours prior)
  When student "e20220001" cancels their registration
  Then the registration status transitions to "Cancelled"
  And the available capacity for "E001" increases by 1 seat
```

---

### US-09: Reject Late Cancellation (Business Rule 3: Boundary & Late Side)
**As an** event organizer,  
**I want** cancellations to be locked inside the 24-hour window,  
**So that** our catering and material preparations do not go to waste.  
*Priority:* Must · *Source:* FR-06 · *Size:* 2 pts

```gherkin
Scenario: Cancellation 1 second too late is rejected (Boundary Test)
  Given event "E001" starts on "2026-11-20 14:00:00"
  And student "e20220001" is registered for "E001"
  And the current system time is "2026-11-19 14:00:01" (23 hours, 59 minutes, 59 seconds prior)
  When student "e20220001" attempts to cancel
  Then the system rejects the cancellation
  And displays "Error: cancellation deadline closed (must cancel strictly 24 hours before start)"
  And registration status remains "Registered"
```

---

### US-10: Opt-In for Reminder Alerts
**As a** student,  
**I want** to opt in for SMS/email event reminders,  
**So that** I don't forget my upcoming workshop.  
*Priority:* Should · *Source:* FR-13 · *Size:* 2 pts

```gherkin
Scenario: Student enables SMS reminders with valid phone
  Given student "e20220001" has reminders defaulted to off
  When the student checks "Enable SMS alerts" and provides "+855 12 345 678"
  Then the phone number is saved
  And reminder preference is set to true
```

---

### US-11: Withdraw Reminder Consent
**As a** student,  
**I want** to withdraw my SMS consent at any time,  
**So that** my phone number is deleted from active storage immediately.  
*Priority:* Should · *Source:* FR-13 · *Size:* 1 pt

```gherkin
Scenario: Student withdraws SMS consent
  Given student "e20220001" has an active phone number on file
  When the student unchecks "Enable SMS alerts"
  Then the stored phone number is erased immediately
  And the system no longer sends SMS alerts
```

---

### US-12: Fast Door Check-In
**As an** event organizer,  
**I want** to validate a student ticket in under 1 second at the door,  
**So that** attendees enter smoothly without queuing in the hallway.  
*Priority:* Must · *Source:* FR-09, FR-10, NFR-01 · *Size:* 5 pts

```gherkin
Scenario: Valid attendee check-in
  Given ticket "TICK-E001-042" is valid for event "E001" with status "Registered"
  When the organizer checks in ticket "TICK-E001-042"
  Then the status transitions to "CheckedIn" in under 1 second
  And the screen displays masked ID "Student{id=e2******1}"

Scenario: Reject duplicate ticket reuse
  Given ticket "TICK-E001-042" was already checked in at "13:50"
  When the organizer scans ticket "TICK-E001-042" again
  Then the system rejects the check-in with "Alert: Ticket already redeemed"
```

---

### US-13: Offline Door Check-In Queue
**As an** event organizer,  
**I want** check-ins to function without network connectivity,  
**So that** entrance operations continue uninterrupted when campus Wi-Fi drops.  
*Priority:* Must · *Source:* FR-11, NFR-03 · *Size:* 5 pts

```gherkin
Scenario: Offline check-in queuing
  Given the venue network is disconnected
  When the organizer checks in 5 valid attendees
  Then all 5 check-ins are recorded locally in the offline queue
  And when network connectivity returns, all 5 records sync with zero lost tickets
```

---

### US-14: View Live Door Headcount
**As an** event organizer,  
**I want** to view real-time counts of checked-in attendees versus room capacity,  
**So that** I know how many seats are currently occupied.  
*Priority:* Should · *Source:* FR-09 · *Size:* 2 pts

```gherkin
Scenario: Display live door stats
  Given event "E001" has capacity 30 and 18 students have checked in
  When the organizer requests the door summary
  Then the system displays "18 / 30 seats checked in (60% occupancy)"
```

---

### US-15: Generate Monthly Attendance Report
**As a** Student Affairs administrator,  
**I want** to generate a monthly attendance report across all clubs,  
**So that** I can allocate semester budget funding based on real participation data.  
*Priority:* Must · *Source:* FR-12 · *Size:* 5 pts

```gherkin
Scenario: Generate anonymized monthly report
  Given 3 clubs hosted 6 events in November 2026 with 155 total attendees
  When the administrator runs the monthly report for "2026-11"
  Then the report outputs total events and attendee counts per club
  And personal student IDs and names are purged from the output
```

---

### US-16: View Masked Roster for Event
**As an** approved club leader,  
**I want** to see the list of students registered for my event,  
**So that** I know attendee names without accessing their private phone numbers.  
*Priority:* Should · *Source:* FR-12, NFR-05 · *Size:* 3 pts

```gherkin
Scenario: Leader views registered attendee roster
  Given student "e20220001" ("Alice") is registered for event "E001"
  When the Robotics Club leader views the roster for "E001"
  Then the output shows name "Alice" and masked ID "e2******1"
  And the student's personal phone and private email are hidden
```

---

## 3. INVEST Quality Check (Sample of 3 Stories)

| INVEST Criterion | **US-05 (Register Event)** | **US-08 (Cancel Registration)** | **US-12 (Door Check-In)** | Evaluation Notes |
| :--- | :---: | :---: | :---: | :--- |
| **Independent** | ✅ Yes | ✅ Yes | ✅ Yes | Stories can be built and tested independently using mocked event data. |
| **Negotiable** | ✅ Yes | ✅ Yes | ✅ Yes | UI presentation (CLI flags vs form) can be adjusted without breaking logic. |
| **Valuable** | ✅ Yes | ✅ Yes | ✅ Yes | Directly solves overbooking, seat wastage, and door congestion. |
| **Estimable** | ✅ Yes (5 pts) | ✅ Yes (3 pts) | ✅ Yes (5 pts) | Sized clearly based on business logic and validation complexity. |
| **Small** | ✅ Yes ($\le 5$ pts) | ✅ Yes ($\le 3$ pts) | ✅ Yes ($\le 5$ pts) | All stories are $\le 8$ points; no large epic needs splitting. |
| **Testable** | ✅ Yes | ✅ Yes | ✅ Yes | Defined with clear, automated Given-When-Then Gherkin acceptance criteria. |