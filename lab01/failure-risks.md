# Failure Risks · ITC Club Hub (v0.1, 2026-10-14)

| # | How the Project Could Fail | Chapter 01 Topic | Early Warning Sign | First Countermeasure | Owner |
| :-: | :--- | :--- | :--- | :--- | :--- |
| **F1** | **Scope Creep / Changing Requirements:** Trying to build a full GUI/Web app instead of focusing on core C++ business rules. | *Essential Difficulty: Changeability* | Backlog grows with non-essential UI features during Sprint planning. | Enforce strict MoSCoW prioritization; keep UI "Modelled only". | Product Owner |
| **F2** | **Communication Bottlenecks:** Team members work in silos, leading to merge conflicts and duplicated work. | *Communication Overhead ($n(n-1)/2$)* | PRs remain unreviewed for >3 days; sudden merge collisions on `main`. | Standup sync twice a week; assign specific module owners. | Scrum Master |
| **F3** | **Unmanaged Technical Debt:** Writing messy monolithic C++ code without modular architecture. | *Cost of Change Curve* | Hard to add new rules without breaking existing build; build warnings ignored. | Enforce `/W4` or `-Wall -Wextra -Wpedantic` with zero warnings from Lab-01. | DevOps Lead |
| **F4** | **Data Race / Inaccurate Capacities:** Two students register simultaneously for the last seat, exceeding venue limit. | *Essential Difficulty: Complexity* | Test logs show over-booking when multiple registrations run. | Implement strict invariant checks in the domain model before committing data. | Lead Developer |
| **F5** | **Last-Minute Integration Disaster:** Code only runs on one student's laptop and fails on others. | *Accidental Difficulty: Tooling Mismatch* | "It works on my machine" excuses during lab checks. | Standardize CMake 3.28+ build scripts and automated GitHub Actions CI. | DevOps Lead |
