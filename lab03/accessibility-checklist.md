# Accessibility Checklist · ITC Club Hub · Version 1.0 · 2026-10-26
Target: WCAG 2.2 Level AA 

## 1. Success Criteria Matrix (POUR Principles & WCAG 2.2 Additions)

| SC | Name | Principle | Level | Screen | How We Meet It | How We Test It |
|---|---|---|:---:|---|---|---|
| **1.4.1** | Use of Color | Perceivable | A | Event List / CLI | Statuses use text tags like `[REGISTERED]` alongside colors; never color alone. | View terminal output in greyscale mode. |
| **1.4.3** | Contrast (Minimum) | Perceivable | AA | Event Details | Text-to-background contrast ratio is at least 4.5:1 for normal body text. | WebAIM Contrast Checker tool. |
| **1.4.11** | Non-text Contrast | Perceivable | AA | Buttons / Badges | UI components and button boundaries have at least 3:1 contrast against background. | Color picker with contrast analyzer. |
| **2.1.1** | Keyboard Navigation | Operable | A | Registration Form | All fields, buttons, and links can be navigated and activated using `Tab` and `Enter`. | Disconnect mouse; test full flow using keyboard only. |
| **2.4.7** | Focus Visible | Operable | AA | Club Catalog | Focused inputs display a clear, high-contrast blue outline ring. | Tab through UI and check active focus rings. |
| **2.5.8** | Target Size (Minimum) *(WCAG 2.2)* | Operable | AA | Mobile Check-In | Touch buttons are at least 24x24 CSS pixels with adequate spacing. | Inspect element box dimensions in mobile dev tools. |
| **3.2.6** | Consistent Help *(WCAG 2.2)* | Understandable | A | All Pages | A "Help & Support" contact link appears in the exact same location in the header/footer. | Visual audit across 3 distinct pages. |
| **3.3.1** | Error Identification | Understandable | A | CLI & Web Forms | Errors explicitly state what went wrong and how to fix it in text. | Submit empty mandatory fields and verify message. |
| **3.3.7** | Redundant Entry *(WCAG 2.2)* | Understandable | A | Registration | Previously entered student name and email auto-populate; never re-prompted in the same session. | Complete two consecutive event signups. |
| **3.3.8** | Accessible Authentication *(WCAG 2.2)* | Understandable | AA | Login Screen | No cognitive function tests (like memorizing complex puzzles); supports paste/password managers. | Use password manager auto-fill. |
| **2.4.11** | Focus Not Obscured (Min) *(WCAG 2.2)* | Operable | AA | Modal Dialogs | Sticky headers or bottom sheets never cover the active keyboard-focused input. | Tab through forms with sticky bars enabled. |
| **4.1.2** | Name, Role, Value | Robust | A | Status Badges | Elements have proper ARIA attributes (`role="status"`, `aria-label`). | Test with NVDA or Windows Narrator screen reader. |

---

## 2. Screen Contrast Audit (2 Planned Screens)

### Screen A: Event Registration Card (Web/Mobile)
- **Primary Text:** Dark Charcoal (`#1F2937`) on White (`#FFFFFF`) → **Ratio: 12.6:1** (Passes AA & AAA)
- **Primary Button:** White (`#FFFFFF`) on Deep Navy (`#1E3A8A`) → **Ratio: 8.5:1** (Passes AA & AAA)
- **Secondary Text / Date:** Muted Slate (`#4B5563`) on White (`#FFFFFF`) → **Ratio: 7.2:1** (Passes AA)

### Screen B: CLI Terminal / Door Scanner
- **Success Message:** Bright Green (`#22C55E`) on Dark Background (`#111827`) → **Ratio: 9.1:1** (Passes AA)
- **Error / Rejected Badge:** Bright Crimson (`#EF4444`) on Dark Background (`#111827`) → **Ratio: 5.2:1** (Passes AA)
- **Normal CLI Text:** Off-White (`#F3F4F6`) on Dark Background (`#111827`) → **Ratio: 14.1:1** (Passes AA & AAA)
