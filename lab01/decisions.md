# Decision Log · Angkor Coders (v0.1, 2026-10-14)

This document tracks all architectural, organizational, and technical decisions made by Team **I2-ISE** for the ITC Club Hub project throughout the semester.

---

## Decision History

| # | Date | Decision | Decided By | Alternatives Considered | Rationale |
| :-: | :---: | :--- | :--- | :--- | :--- |
| **1** | 2026-10-14 | **Team Name:** Selected **"I2-ISE"** as official team identity, repository suffix (`clubhub-I2-ISE`), and banner string (`kTeamName`). | Team Vote (4–1) | 1. *"Byte Masters"*<br>2. *"I2-ISE"*<br>3. *"ITC Terminal Warriors"* | *"I2-ISE"* is concise, professional, represents our Cambodian identity, and fits within the 40-character CLI startup banner limit. |
| **2** | 2026-10-14 | **Team Roles & SM Rotation:** <br>• Product Owner: Chan Dara (fixed all semester)<br>• Sprint 1 Scrum Master: Sokha Pich<br>• Sprint 2 Scrum Master: Minea Heng | Consensus (all 5 members) | Rotating Product Owner every sprint. | Keeping the Product Owner fixed maintains a stable relationship with the client (TA/Instructor). Rotating the Scrum Master gives two developers leadership experience. |
| **3** | 2026-10-14 | **Primary Communication Stack:** <br>• Urgent chats: Telegram group<br>• Task management: GitHub Issues & Projects<br>• Code reviews: GitHub Pull Requests | Unanimous (5–0) | 1. Discord server<br>2. Facebook Messenger group | Telegram allows fast mobile notifications without distracting feeds. Discord was rejected because not all members have it running actively. Facebook lacks thread organization and code formatting. |
| **4** | 2026-10-14 | **Failure Case Study Choice (Task 3):** Selected the **Knight Capital 2012 Trading Glitch** for the failure analysis report. | Facilitator & Developers | 1. Therac-25<br>2. CrowdStrike 2024 outage | Knight Capital provides a clear example of Brooks's *Complexity* and *Changeability*, specifically demonstrating dead code reuse and deployment automation failures. |
| **5** | 2026-10-14 | **Compiler Baseline:** Enforce GCC 13+ / MSVC 19.38+ with `-Wall -Wextra -Wpedantic` (or `/W4` on MSVC) with zero warnings allowed. | DevOps Lead & Developers | Allowing optional warnings during early development. | Enforcing zero warnings from day one prevents technical debt from accumulating before unit tests are added in Lab-04. |

---

## How to Add New Entries
Whenever a major choice is made in future labs (e.g., choosing an open-source license in Lab-03, selecting a JSON parser in Lab-04, or establishing branching policies in Lab-08):
1. Add a new numbered row at the bottom of the table.
2. Clearly state **who made the decision** and the **method** (vote, consensus, or role authority).
3. Document **at least one rejected alternative** and the specific reason why it was not selected.
