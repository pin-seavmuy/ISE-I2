# SRS Review Checklist & Peer Review Report
Reviewer Team: Team I2-ISE  
Reviewed Document: Partner Team SRS (`clubhub/lab05/srs.md`)  
Standard: ISO/IEC/IEEE 29148 Review Checklist  
Review Date: 2026-11-14

---

## 1. Review Checklist

| # | Inspection Item | Pass / Fail | Findings & Concrete Recommendations |
| :---: | :--- | :---: | :--- |
| **1** | Every requirement has a unique, unambiguous identifier and a traceable source. | **Pass** | All requirements are tagged with unique IDs (`FR-01`, `NFR-01`) traced to raw needs. |
| **2** | All functional requirements strictly use normative language ("The system shall..."). | **Pass** | Clean use of "shall" throughout Section 3.2. |
| **3** | Requirements avoid ambiguous weak words ("fast", "user-friendly", "easy", "etc."). | **Fail** | **Finding 1:** FR-02 stated "The system shall provide an easy registration process." Changed to: "The system shall record registration in under 60 seconds." |
| **4** | Every business rule is explicitly formulated as an independent requirement. | **Fail** | **Finding 2:** 24-hour cancellation rule only covered the allowed side. Added separate requirement for late cancellation rejection. |
| **5** | All Non-Functional Requirements specify quantifiable, measurable targets. | **Fail** | **Finding 3:** NFR-02 stated "Door check-in must be fast." Quantified as: "Latency $< 1.0$ second for 95% of transactions." |
| **6** | Personal data protection and privacy constraints are explicitly stated. | **Pass** | Student ID masking and phone consent withdrawal are well specified. |
| **7** | Scope clearly demarcates in-scope features from out-of-scope exclusions. | **Fail** | **Finding 4:** Payment processing was not listed under exclusions. Added to Section 1.2 Out of Scope. |
| **8** | Section 4 provides a concrete verification method (Test, Inspection, Demo) for every ID. | **Pass** | Complete verification matrix mapping each ID to an automated test or inspection. |

---

## 2. Summary of Key Findings & Resolutions (8 Findings)

1. **Finding 1 (Weak word eliminated):** Replaced vague phrase *"easy registration"* with concrete step-by-step validation.
2. **Finding 2 (Missing business rule boundary):** Added explicit boundary requirement for cancellations occurring $< 24$ hours prior to start.
3. **Finding 3 (Quantified check-in latency):** Replaced *"rapid check-in"* with exact metric: *"$< 1.0$ second response time for 95% of scans"*.
4. **Finding 4 (Scope boundary clarification):** Explicitly added external online payment gateways and in-app chat to Excluded Scope.
5. **Finding 5 (Offline queue idempotency):** Added requirement ensuring offline check-in transactions use idempotency keys to prevent network sync duplication.
6. **Finding 6 (Admin reporting privacy):** Added clause to monthly reporting specifying that student names and IDs must be purged from administrative outputs.
7. **Finding 7 (Missing definition):** Added definition for *Idempotency Key* and *Cancellation Cutoff* to Section 1.4 Definitions.
8. **Finding 8 (Crash recovery metric):** Quantified crash recovery time to within 5 seconds without database corruption.

**Conclusion:** All 8 findings resolved and incorporated into **SRS Version 1.0**.