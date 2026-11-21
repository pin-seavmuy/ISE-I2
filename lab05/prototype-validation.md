# Prototype Usability Validation Report · Lab-05 Challenge
**Target Feature:** Student Event Registration & Cancellation Flow  
**Prototype Path:** [`lab05/prototype/index.html`](./prototype/index.html)  
**Date:** 2026-11-21 · **Evaluators:** Team I2-ISE

---

## 1. Evaluation Protocol

We conducted "Think-Aloud" usability testing with **2 external students** outside of the ISE software engineering project team.

### Participants:
* **Student A (Participant 1):** Kim Chanthou — Year 2 Telecommunications & Networking (familiar with web forms, has not used ClubHub).
* **Student B (Participant 2):** Leng Rithy — Year 3 Civil Engineering (general smartphone user, active member of university football club).

### Usability Tasks:
1. **Task 1 (Discovery & Registration):** Browse the catalog for an available workshop and register for it.
2. **Task 2 (Capacity Constraint Awareness):** Find the sold-out event and observe how full capacity is communicated.
3. **Task 3 (Self-Service Cancellation):** Locate your digital entry pass and cancel registration prior to the 24-hour cutoff deadline.

---

## 2. Think-Aloud Observations & Findings

| ID | Participant | Task | Observation / Quote | Severity | Category |
| :---: | :---: | :---: | :--- | :---: | :---: |
| **OBS-01** | Student A | Task 1 | *"I got my confirmation code `ITC-ROB-4921`, but can I download a calendar invite (`.ics`) or send it to Telegram so I don't forget?"* | Low | Usability Enhancement |
| **OBS-02** | Student B | Task 2 | *"The event is full, but I want to be added to an automated queue that automatically registers me if someone cancels, rather than just an alert."* | Medium | Scope Expansion |
| **OBS-03** | Student A & B | Task 3 | *"The warning says 24h deadline, but it doesn't state the exact cutoff time on the My Passes screen in countdown format (e.g., '14 hours remaining to cancel')."* | High | Clarity & Requirement Gap |
| **OBS-04** | Student B | Task 1 | Confused whether ticket confirmation required email validation before door scan. | Low | Information Architecture |

---

## 3. Findings Synthesis & Actionable Decisions

1. **Rejected for v1.0 (Out of Scope):** Automatic waitlist promotion (OBS-02). Automating instant reservation reallocation requires handling payment/confirmation windows which violates our current simple CLI scope.
2. **Accepted as Formal Change Request (CR-001):** **Explicit Countdown & Timestamp for 24h Cancellation Deadline (OBS-03)**. The SRS currently states the rule in abstract terms ("24 hours prior"), but users need the exact system cutoff timestamp displayed on all registration views to eliminate cancellation disputes.
