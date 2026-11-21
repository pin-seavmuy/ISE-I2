# Lab-05: Requirements Engineering · ITC Club Hub
**Team:** I2-ISE · **Branch:** `lab-05` · **Date:** 2026-11-20

---

## 1. Deliverables Summary

| File | Description | Status |
| :--- | :--- | :---: |
| [`interview-script.md`](./interview-script.md) | Semi-structured interview protocol with 12 open/probing questions | Complete |
| [`interview-notes.md`](./interview-notes.md) | Synthesized transcript with quantified metrics and raw stakeholder quotes | Complete |
| [`raw-needs.csv`](./raw-needs.csv) | 16 extracted stakeholder needs mapped to source roles and categories | Complete |
| [`requirements.md`](./requirements.md) | 13 Functional (FR) and 7 Non-Functional (NFR) requirements with verification methods | Complete |
| [`conflicts.md`](./conflicts.md) | Resolution matrix for 3 core stakeholder conflicts (C1, C2, C3) with trade-off rationale | Complete |
| [`user-stories.md`](./user-stories.md) | 16 INVEST user stories with 32+ executable Gherkin acceptance criteria | Complete |
| [`use-case-register.md`](./use-case-register.md) | Detailed textual use case specification for UC-02 (Register for Event) | Complete |
| [`srs.md`](./srs.md) | Formal ISO/IEC/IEEE 29148:2018 SRS baseline v1.0 (zero ambiguous weak words) | Complete |
| [`srs-review.md`](./srs-review.md) | Peer review inspection report with 8 constructive findings resolved | Complete |
| [`backlog.csv`](./backlog.csv) | Prioritized product backlog with Planning Poker points, MoSCoW, value, and issue mapping | Complete |
| [`traceability.csv`](./traceability.csv) | Requirements Traceability Matrix (RTM) linking FR/NFRs to stories and tests | Complete |
| [`README.md`](./README.md) | Master synthesis, capacity calculations, quadrant chart, and change log | Complete |
| [prototype/index.html](./prototype/index.html) | Interactive 5-screen usability prototype for registration & cancellation | Complete |
| [prototype-validation.md](./prototype-validation.md) | Usability report with 2 external students and think-aloud findings | Complete |
| [change-requests/CR-001.md](./change-requests/CR-001.md) | Formal Change Request for cancellation cutoff countdown timestamp | Complete |

---

## 2. Reused Inputs from Previous Labs

* **Lab-01 & Lab-02 Domain Constraints:** Reused domain models (`Event`, `Student`, `Registration`) and non-functional requirements (NFR-01 latency $\le 1.0\text{s}$, NFR-02 crash recovery $\le 5.0\text{s}$, offline queue idempotency).
* **Lab-03 Ethics & Privacy Policies:** Reused privacy consent notice (opt-in/opt-out for notifications), GDPR/APEC privacy rules, student ID masking (`s*****@itc.edu.kh`), and retention rules.
* **Lab-04 Process & Planning:** Reused PDR-001 hybrid Scrum process decision, 2-week sprint rhythm, and sprint team capacity formula ($48\text{ hours/sprint}$).

---

## 3. Backlog Estimation & MoSCoW Distribution

### 3.1 Capacity & Must-Share Rule
According to the course guidelines, **Must-have** stories must not exceed **60%** of total estimated story points to guarantee schedule buffer against unforeseen risks:

$$\text{Must Share} = \frac{\sum \text{Must Points}}{\sum \text{Total Points}} \times 100\%$$

* **Total Backlog Points:** $52\text{ pts}$ (16 user stories)
* **Must-have Points:** $28\text{ pts}$ (8 user stories: US-03, US-04, US-05, US-06, US-07, US-08, US-09, US-12)
* **Should-have Points:** $24\text{ pts}$ (8 user stories: US-01, US-02, US-10, US-11, US-13, US-14, US-15, US-16)

$$\text{Must Share} = \frac{28}{52} \times 100\% = \mathbf{53.8\%} \le 60\% \quad \text{(Compliant with Rule!)}$$

---

## 4. Value vs. Effort Prioritization Matrix

```mermaid
quadrantChart
    title Backlog Prioritization: Value vs Effort
    x-axis Low Effort (1-3 pts) --> High Effort (5-8 pts)
    y-axis Low Value (1-3) --> High Value (4-5)
    quadrant-1 "High Value, Complex (Sprint 1 Core)"
    quadrant-2 "Quick Wins (High Priority)"
    quadrant-3 "Low Value, Low Effort"
    quadrant-4 "Complex, Lower Priority"
    "US-03 Publish Event": [0.75, 0.90]
    "US-04 Browse Events": [0.45, 0.90]
    "US-05 Register Event": [0.75, 0.95]
    "US-06 Duplicate Check": [0.25, 0.80]
    "US-07 Capacity Check": [0.45, 0.90]
    "US-08 24h Cancellation": [0.45, 0.85]
    "US-09 Reject Late Cancel": [0.25, 0.80]
    "US-12 Door Check-In": [0.75, 0.95]
    "US-13 Offline Queue": [0.75, 0.70]
    "US-15 Admin Report": [0.75, 0.70]
    "US-10 Reminders": [0.30, 0.45]
    "US-11 Withdraw Consent": [0.15, 0.45]
```

---

## 5. Requirements Traceability Gaps
* **Coverage:** All 13 Functional Requirements (`FR-01` to `FR-13`) and 7 Non-Functional Requirements (`NFR-01` to `NFR-07`) are mapped 1-to-1 or 1-to-many against corresponding user stories and planned unit test cases in [`traceability.csv`](./traceability.csv).
* **Unmapped Gaps:** **0 gaps (100% full bidirectional traceability)**.

---

## 6. Document History & Change Log

| Version | Date | Author | Description of Change |
| :---: | :---: | :--- | :--- |
| **0.1** | 2026-11-14 | Team I2-ISE | Initial draft of interview notes and raw needs extraction. |
| **0.2** | 2026-11-14 | Team I2-ISE | Requirements classification and stakeholder conflict resolution. |
| **0.3** | 2026-11-14 | Team I2-ISE | User stories with Gherkin acceptance criteria and UC-02 specification. |
| **1.0** | 2026-11-14 | Team I2-ISE | Formal ISO 29148 SRS baselined (`srs-v1.0`), peer review audit completed, backlog prioritized, and traceability matrix generated. |

