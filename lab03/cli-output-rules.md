# CLI Output Accessibility Rules · ITC Club Hub Version 1.0 · 2026-10-26

## Rule 1: Never Use Colour Alone to Convey Status
- **Why:** Color-blind users cannot distinguish red text from green text.
- **Bad:** `\033[32mEvent 101\033[0m` (only color tells the user it is open).
- **Good:** `[OPEN] Event 101` (text badge clearly conveys state even in monochrome).

## Rule 2: Respect the `NO_COLOR` Environment Standard
- **Why:** Accessibility tools and users with customized terminal contrast need plain text.
- **Bad:** Hardcoding ANSI escape codes (`\033[31m`) with no option to disable them.
- **Good:** If the `NO_COLOR` environment variable is set or `--no-color` is passed, strip all ANSI codes.

## Rule 3: Use Standard, Unambiguous Date Formats (ISO 8601)
- **Why:** Screen readers and international students get confused by `03/04/2026` (March 4 vs April 3).
- **Bad:** `Date: 03/04/26`
- **Good:** `Date: 2026-04-03 14:00`

## Rule 4: Actionable Error Messages with "Next Step"
- **Why:** Users need to know how to recover from an error immediately.
- **Bad:** `Error: Registration failed.`
- **Good:** `Error: Registration closed. Why: Capacity (50/50) reached. Next step: Run 'clubhub waitlist 101' to join the waiting list.`

## Rule 5: Keep Table Outputs Predictable and Screen-Reader Friendly
- **Why:** Screen readers read line by line. ASCII art decoration breaks speech synthesizers.
- **Bad:** Using decorative ASCII borders: `+~~~=***=~~~+`
- **Good:** Use clean standard separators or CSV/JSON mode for screen-reading software.

## Rule 6: Left-Align Text and Right-Align Numbers
- **Why:** Consistent alignment helps users with low vision or magnification tools scan columns.
- **Bad:** Center-aligning all table columns haphazardly.
- **Good:** IDs, Titles, and Statuses are left-aligned; Capacities, Counts, and Prices are right-aligned.
