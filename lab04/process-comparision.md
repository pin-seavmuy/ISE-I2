# Process Comparison · Team I2-ISE · v1.0 (2026-11-03)

Scale: 1 = fits Club Hub badly, 5 = fits Club Hub very well.

| Criterion | Weight | Waterfall | Incremental | Scrum-style | Justification (Team Agreement) |
| :--- | :---: | :---: | :---: | :---: | :--- |
| **Requirements stability** | **25%** | 2 | 4 | **5** | Client only gives a brief case study; features and edge cases evolve as we discover them. |
| **Client availability** | **20%** | 1 | 3 | **4** | Client (TA) is only available ~30 mins a week; Waterfall requires months of upfront signing, while Scrum needs just brief sprint reviews. |
| **Team experience** | **20%** | 2 | 4 | **4** | Team is learning C++20 and CMake; working in small iterations lets us learn without breaking everything. |
| **Deadline (Week 14)** | **20%** | 2 | 4 | **5** | Semester has a hard deadline (Week 14); Waterfall risks running out of time during testing, while Scrum guarantees working code every sprint. |
| **Risk management** | **15%** | 1 | 4 | **5** | High risk of misunderstood rules (e.g., 24h cancellation); Scrum uncovers bugs early in Sprint 1 rather than at the end. |
| **Total Weighted Score** | **100%** | **1.65** | **3.80** | **4.60** | **Winner: Scrum-style Iterative** |

---

## 1. Why These Weights?

- **Requirements stability (25%):** Our highest weight. In student projects, requirements are never 100% fixed at the start; choosing a process that handles change is critical.
- **Client availability (20%):** Our TA/client is busy and can only meet during lab sessions. We cannot spend 4 weeks waiting for formal requirement sign-offs.
- **Team experience (20%):** We are 2nd-year students still mastering modern C++ tools. Short iterations keep tasks manageable.
- **Deadline Week 14 (20%):** University semester cannot be extended. We must have a working demo ready by Week 14 no matter what.
- **Risk management (15%):** Catching architecture and privacy bugs early prevents last-minute failures.

---

## 2. Calculation in Full for One Model (Scrum-style)

$$\text{Weighted Score} = \sum \frac{(\text{Weight} \times \text{Score})}{100}$$

$$\begin{aligned}
\text{Scrum Score} &= \frac{(25 \times 5) + (20 \times 4) + (20 \times 4) + (20 \times 5) + (15 \times 5)}{100} \\
&= \frac{125 + 80 + 80 + 100 + 75}{100} \\
&= \frac{460}{100} = \mathbf{4.60}
\end{aligned}$$

*(Waterfall = 1.65 / 5.00 · Incremental = 3.80 / 5.00)*

---

## 3. Sensitivity Check

To test if our decision is solid, we move **10 points** from our heaviest criterion (**Requirements stability**, 25% &rarr; 15%) to our lightest criterion (**Risk management**, 15% &rarr; 25%):

- **New Waterfall score:** 1.55 (Drops)
- **New Incremental score:** 3.80 (Unchanged)
- **New Scrum-style score:** **4.60** (Unchanged)

👉 **Result:** Even after changing the weights, **Scrum-style iterative remains the clear winner**. The decision is stable!

---

## 4. Conclusion

- **Winner:** The **Scrum-style iterative model** scored the highest (**4.60 / 5.00**). It best matches our academic calendar, weekly meetings, and student learning curve.
- **Weakness we must manage:** Scrum requires disciplined meetings and steady weekly commits. If members procrastinate until the end of the sprint, the iteration fails.
- **Hybrid approach:** A pure Scrum model without any upfront thinking can cause poor architecture. Therefore, our team adopts a **pragmatic hybrid**: we spend Weeks 5–7 doing initial requirements (SRS) and architecture modeling, followed by two 2-week Scrum sprints (Weeks 9–12) for implementation and testing.