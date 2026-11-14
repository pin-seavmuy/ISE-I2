# Stakeholder Conflicts & Resolutions · ITC Club Hub
Version 1.0 · 2026-11-14 · Lead: Sok Dara (Product Owner)

---

## Conflict C1 · Student Phone Number: Mandatory vs. Optional

- **Positions:**
  - *Event Organiser:* Demands that phone numbers be **mandatory** during registration to call students who are late or need urgent room change directions.
  - *Student Representative:* Demands that phone numbers remain **optional**, as students are uncomfortable sharing personal contact numbers with student club organizers due to privacy concerns and spam risks.
- **Underlying Interests:**
  - Organisers need a reliable channel to communicate time-sensitive event alerts.
  - Students need protection against unsolicited messages, spam, and privacy leaks.
- **Options Considered:**
  - *(a)* Make phone number mandatory for everyone.
  - *(b)* Make phone number strictly optional, relying only on institutional email.
  - *(c)* Phone number is optional (opt-in) with an explicit SMS consent checkbox; urgent broadcasts go via push notification / institutional email; organizers never see the raw phone number on screen.
- **Decision:** **Option (c).**
- **Rationale:** Under GDPR purpose limitation and the Lab-03 Data Inventory, personal phone numbers require explicit opt-in consent and cannot be forced as a condition of service. Organisers do not need personal phone numbers if the system automatically handles broadcast announcements.
- **Requirements Created/Updated:**
  - `FR-13` (Opt-in consent for phone alerts).
  - `NFR-05` (Phone numbers masked/hidden from organizer screens).
- **Client Agreement:** Agreed by Instructor/Client on 2026-11-14.

---

## Conflict C2 · Cancellation Cutoff Window: Event Start vs. 48 Hours Before

- **Positions:**
  - *Club President:* Wants cancellations allowed right up until the event start time so students have maximum flexibility.
  - *Event Organiser:* Demands that cancellations close **48 hours before**, because they must purchase food, print badges, and prepare hardware kits two days in advance.
- **Underlying Interests:**
  - The Club President wants high turnout and happy attendees.
  - The Organiser wants predictable headcounts to prevent wasted materials, budget losses, and empty seats.
- **Options Considered:**
  - *(a)* Allow cancellations up to the exact minute of start time.
  - *(b)* Lock cancellations 48 hours before the start.
  - *(c)* Compromise at strictly **24 hours before event start**.
- **Decision:** **Option (c) — Strict 24-Hour Cancellation Deadline.**
- **Rationale:** 48 hours is too rigid for university students whose study schedules change quickly; allowing cancellations right up to the start causes sudden 30% empty seats that cannot be refilled. The 24-hour cutoff gives organizers one full working day to reassign open seats while giving students a fair cancellation window.
- **Requirements Created/Updated:**
  - `FR-05` (Allowed cancellation $\ge 24$h before start).
  - `FR-06` (Rejected cancellation $< 24$h before start).
- **Client Agreement:** Agreed by Instructor/Client on 2026-11-14.

---

## Conflict C3 · Event Approval: Administrative Pre-Approval vs. Immediate Publishing

- **Positions:**
  - *Student Affairs Administrator:* Demands to review and approve **every single event** before it becomes visible to students to ensure university venue safety and alignment with academic policies.
  - *Club Leaders:* Demand **immediate, same-day publishing** of events, arguing that admin approval takes 3–5 business days and ruins quick workshops and weekly study groups.
- **Underlying Interests:**
  - Administration requires governance, venue deconfliction, and legal oversight.
  - Club Leaders require autonomy and agile event scheduling without bureaucratic roadblocks.
- **Options Considered:**
  - *(a)* Every event requires individual administrator pre-approval before publication.
  - *(b)* Club leaders publish events instantly with zero administrative oversight.
  - *(c)* Two-tier model: The administrator approves the **Club itself** (one-time vetting); once approved, verified club leaders publish standard events immediately within their quota, subject to post-publishing admin audit and revocation.
- **Decision:** **Option (c) — One-time Club Approval with Direct Event Publishing.**
- **Rationale:** The Student Affairs Office lacks the administrative staffing to review 50 individual event submissions each month. Vetting the club charter and club executive officers once (`ClubStatus::Approved`) provides necessary governance while allowing clubs to operate dynamically.
- **Requirements Created/Updated:**
  - `FR-08` (Only approved clubs can publish events).
  - Domain model state `ClubStatus` (`Pending`, `Approved`, `Rejected`).
- **Client Agreement:** Agreed by Instructor/Client on 2026-11-14.