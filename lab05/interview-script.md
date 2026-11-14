# Interview Script · ITC Club Hub
Version 1.0 · 2026-11-14 · Team: I2-ISE

**Client Role(s):** Club President (Robotics Club) & Event Organiser at the Door  
**Interview Goals:**
1. Understand how club events are planned, announced, and registered today, and where the current process fails.
2. Identify the exact requirements and constraints for door check-in, capacity control, and cancellation deadlines.
3. Clarify data privacy limits: what student personal data is necessary versus what should remain private.

**Team Roles:**
- **Lead Interviewer (Product Owner):** Sok Dara
- **Note-Taker:** Chan Minea
- **Time-Keeper:** Pich Sovann
- **Technical Observers:** Pin Seavmuy, Tep Bopha

---

## 1. Opening (2 min)
- Thank the client for their time.
- State purpose: *"We are designing ITC Club Hub to replace manual paper forms and social media announcements with an integrated platform."*
- Ask permission to take notes and record key numbers.

## 2. Context & Current Process (5 min)
1. *Could you walk us through the last event your club organized from planning to wrap-up?*
2. *How do students currently discover your events and sign up for them?*
3. *What tools (Telegram, Google Forms, paper sign-up sheets) do you currently use, and how do they interact?*

## 3. Needs & Pain Points (8 min)
4. *What goes wrong most often with event registrations today?*
5. *How do you handle capacity limits when more students sign up than the room can hold?*
6. *What happens when students register but do not show up on event day?*
7. *How does check-in work at the door when attendees arrive?*
8. *What information do you need to see about a student when they arrive at the entrance?*
9. *What reporting or statistics does the Student Affairs Office require after your event finishes?*

## 4. Probing for Numbers & Edge Cases (3 min)
10. *You mentioned check-in must be "fast." In seconds, what is an acceptable check-in time per student so the entrance line doesn't stall?*
11. *What happens if the campus Wi-Fi or mobile 4G drops completely at the door?*
12. *Until when should students be allowed to cancel their registration without penalty?*
13. *What personal student data (phone number, national ID, academic grades) should club leaders NEVER have access to?*

## 5. Wrap-up (2 min)
14. *What critical feature or issue should we have asked you about that we did not cover today?*
- Summarize the top 3 needs heard today:
  1. Automated capacity enforcement with duplicate registration blocking.
  2. Offline-capable, sub-second QR door check-in.
  3. Strict 24-hour cancellation window with attendance reporting.
- Agree on follow-up channel (GitHub issues/email) for open questions.