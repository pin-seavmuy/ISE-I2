# Ethics Case Analyses · ITC Club Hub Version 1.0 · 2026-10-26 
Leads: Scenario A = Lead Developer, Scenario B = Scrum Master

---

## Scenario A: "Just a small report"
*The Robotics Club leader asks your team to add a report, visible only to club leaders, showing which students attended other clubs' events, "so we can recruit the active ones."*

| Step | Analysis |
|---|---|
| **1. Facts** | The Robotics Club leader wants cross-club attendance records of students to recruit active attendees. What we know: attendance was collected only to manage individual club events, not for inter-club recruiting. What we need to find out: Did students ever consent to have their attendance tracked and shared across other clubs? (No). |
| **2. Stakeholders & Harms** | **Students:** Loss of privacy, feeling tracked/monitored across campus activities, unexpected recruitment spam. **Other Clubs:** Unfair poaching of their active members. **Club Hub Team:** Violation of user trust and our published privacy notice. |
| **3. Codes, Law, Policy** | **SE Code 1.03:** Approve software only if it is safe and does not diminish quality of life or privacy. **ACM Code 1.6:** Respect privacy and only access personal data when authorized for specific purposes. **GDPR Purpose Limitation (Art. 5(1)(b)):** Data collected for event check-in cannot be repurposed for competitor club recruiting. |
| **4. Options** | **(a)** Build the report as requested. **(b)** Flatly reject without explanation. **(c)** Reject the individual tracking report; propose an open "Co-hosted Events" or opt-in "Inter-Club Recruitment Fair" feature instead. |
| **5. Ethical Tests** | • *Harm Test:* Option (a) harms student trust and exposes personal schedules. Option (c) creates zero privacy harm.<br>• *Rights Test:* Students have the right to attend an event without being put on an undisclosed recruitment list.<br>• *Fairness Test:* Giving one club leader access to spy on other clubs' attendees is unfair.<br>• *Publicity Test:* Would we feel proud if ITC The Phnom Penh Post published: "ITC Club Hub exposes student event habits to club recruiters"? No. |
| **6. Decision & Action** | **Choose Option (c):** Refuse the cross-club tracking report. Explain our privacy commitment and offer a legitimate recruitment channel (opt-in joint events). |
| **7. Reflection** | Feature requests often sound harmless to enthusiastic leaders but break fundamental privacy boundaries. We must enforce Role-Based Access Control (RBAC) in code so data cannot leak across clubs. |

**Message Sent to Club Leader (105 words):**  
> *"Hi Robotics Club Team. Thank you for reaching out. Under ITC Club Hub’s Privacy Policy and university data protection rules, attendance records are strictly restricted to the specific organizers of that event and cannot be shared across other clubs. Repurposing attendance data for unsolicited recruitment would violate students' privacy expectations. Instead, we can help you publish an official 'Robotics Club Recruitment Event' on Club Hub, or you can co-host an event with partner clubs where attendees voluntarily register with both organizations. Let us know if you'd like help setting that up!"*

**Preventive Engineering Change:**  
Implement strict club-boundary scoping in data query services so club leaders can never query registrations outside their own club ID (`RegistrationService::getByClubId(callingClubId)`).  
*(Linked Issue: `#12 - Enforce club-level tenancy isolation on attendance queries [label: ethics]`)*

---

## Scenario B: "Don't mention it in the demo"
*Two days before the Sprint 1 review, a developer finds that cancellations inside the 24-hour window are accepted, and that the monthly report counts cancelled registrations as attendance. The Scrum Master says: "Don't mention it in the demo, we'll fix it in Sprint 2."*

| Step | Analysis |
|---|---|
| **1. Facts** | Two critical bugs exist: late cancellations (<24h) are improperly accepted, and cancelled registrations erroneously inflate monthly attendance numbers. The Scrum Master advises hiding this defect during the client demo. |
| **2. Stakeholders & Harms** | **Clubs Office (Client):** Receives falsified attendance statistics, leading to incorrect budget/room allocation. **Organizers:** Plan food/seating for students who actually cancelled. **The Team:** Damage to professional integrity and credibility if discovered by the client later. |
| **3. Codes, Law, Policy** | **SE Code 1.06:** Be honest and realistic in stating claims and estimates. **SE Code 6.07:** Do not withhold technical problems from clients. **ACM Code 1.4:** Be fair and take action not to discriminate or deceive. |
| **4. Options** | **(a)** Obey the SM: Hide the bugs in the demo and patch silently later. **(b)** Publicly blame the developer in front of the client. **(c)** Demo the working features transparently, document both bugs as known issues on the Sprint 1 backlog, and present the planned Sprint 2 fix. |
| **5. Ethical Tests** | • *Harm Test:* Hiding bugs risks the client making real administrative decisions based on fake numbers.<br>• *Rights Test:* The client has a contractual right to know the true status of the product.<br>• *Professional Integrity Test:* Transparent reporting of bugs is standard software engineering practice; deception is not. |
| **6. Decision & Action** | **Choose Option (c):** Present completed features honestly. Openly state the two known defects during the "Known Limitations" slide and demonstrate the unit test written to reproduce and fix them. |
| **7. Reflection** | Hiding bugs under sprint deadline pressure creates technical and ethical debt. A sprint review is an inspection and adaptation meeting, not a theatrical performance. |

**Message Sent to Scrum Master & Product Owner (98 words):**  
> *"Hi Team. Hiding the cancellation bug and inflated attendance reporting in our Sprint 1 demo violates our transparency commitment to the client (SE Code 6.07). If the Clubs Office bases room allocations on these distorted reports, it will cause real logistical failures. During the demo, we should present our completed features proudly, then present a 'Known Limitations' slide showing the cancellation edge cases, along with the reproduction test we already opened in our backlog for Sprint 2. Being upfront demonstrates engineering maturity and builds trust with our client."*

**Preventive Engineering Change:**  
Add automated regression integration tests for the 24-hour cancellation rule and attendance aggregation queries to prevent reporting falsification.  
*(Linked Issue: `#13 - Add automated invariant tests for 24h cancellation rule and attendance counts [label: ethics]`)*
