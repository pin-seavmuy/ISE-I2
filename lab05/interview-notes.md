# Interview Notes · ITC Club Hub
Date: 2026-11-14 · Duration: 20 minutes  
Client: Instructor - Mr.Jonh
Attendees: 
Duration: 20min
---

## Question 1: Last Event Walkthrough
> "Last month we organized a 40-person Arduino workshop in Building I. We posted a Telegram banner with a Google Form link. Within 2 hours, 65 people submitted the form because Google Forms didn't close automatically when full. We had to manually email 25 students apologizing that there was no room."

## Question 2 & 3: Discovery & Current Tools
> "Everything is scattered. Announcements are in 5 different Telegram channels and Facebook groups. Registrations are on Google Forms. Attendance is taken on a printed paper sheet on a clipboard at the door."

## Question 4 & 5: Failure Modes & Capacity Limits
> "The biggest disaster is room overbooking. Room I-201 strictly holds 40 seats due to safety rules. When 50 show up, people sit on the floor or argue with organizers. We need a system that cuts off registration the exact millisecond the last seat is claimed."

## Question 6: No-Shows & Cancellations
> "About 30% of registered students don't show up because there is no penalty and no easy way to cancel. If someone knows they can't come, they should cancel early so students on a waiting list get their seat."

## Question 7 & 8: Check-in at the Door
> "Organizers hold a paper list and a pen. Students say their name or student ID, the organizer scans the paper with their eyes, checks the box, and hands them a badge. When 40 students arrive at 13:55 for a 14:00 workshop, the hallway becomes completely blocked."

## Question 9: Reporting to University Administration
> "The Student Affairs Office requires a monthly report of total student participation for club grant funding. Currently, club secretaries spend 4 hours counting paper check-ins and typing them into Excel."

## Probing & Adjectives Turned into Measurable Numbers:
- **Probing on "Fast Check-in":**
  > *Interviewer:* "You said check-in must be fast. What does fast mean in seconds?"  
  > *Client:* **"It must take under 3 seconds per student.** If someone shows a ticket or QR, scanning and confirmation must take **less than 1 second**, or a line of 50 students will take 15 minutes to clear."
- **Probing on Network Failure (Offline requirement):**
  > *Interviewer:* "What happens if campus Wi-Fi drops at the doorway?"  
  > *Client:* **"Wi-Fi always dies on the 3rd floor.** Check-in **must work 100% offline**. Organizers cannot wait for a spinning loading wheel while students wait outside."
- **Probing on Cancellation Cutoff:**
  > *Interviewer:* "When should cancellation close?"  
  > *Client:* **"Strictly 24 hours before the event start.** If an event starts Saturday at 14:00, cancellations must close Friday at 14:00 so organizers have time to reassign seats or prepare food/materials."
- **Probing on Privacy:**
  > *Client:* **"Organizers only need to see the student's name and a masked ID.** Club leaders must never see personal phone numbers or academic records. Attendance records must belong only to the host club, not shared across clubs."

## Wrap-up & Open Questions Sent to Client
1. *Open Question 1:* If an event reaches capacity, should the waiting list automatically promote the next student if someone cancels, or notify them to claim it?  
   *Client Answer:* "Auto-promotion with an email notification is ideal, but for Sprint 1, simply freeing the seat for anyone is acceptable."
2. *Open Question 2:* What identifier format is official for ITC students?  
   *Client Answer:* "Standard institutional IDs starting with 'e' followed by 8 digits, e.g., `e20220001`."