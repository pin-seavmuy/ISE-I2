# Problem Statement · ITC Club Hub (v0.1, 2026-10-14)

## 1. Problem Definition
The problem of **uncoordinated club event announcements and manual paper/Google Sheet registrations** affects **ITC students and club leaders**; the impact of which is **duplicate registrations, unmonitored room overcapacity, and students missing campus events**. A successful solution would **provide a centralized system to browse approved events, enforce strict seat limits, and streamline on-site attendance check-in**.

## 2. Product Vision
* **For** ITC students and club organizers
* **Who** need a reliable way to publish and join campus club activities,
* **ITC Club Hub** is a centralized event management platform
* **That** guarantees strict seat capacities, enforces registration rules, and tracks verified attendance.
* **Unlike** scattered Telegram channels and unlinked Google Forms,
* **Our product** prevents double bookings, validates student eligibility, and produces verified attendance records.

## 3. Today's Workaround
Currently, clubs advertise on Facebook pages and Telegram groups, collecting participant names via Google Forms. Organizers manually count rows in Excel to prevent overcapacity, which often fails when simultaneous submissions occur.

## 4. Scope
* **Built in C++20 this semester:** Domain logic, business rule enforcement (no double booking, capacity limits, 24h cancellation cut-off), CLI front end, and CSV/JSON file persistence.
* **Modelled only (Diagrams & Architecture):** Web client and Mobile application interfaces (Labs 02 & 06).
* **Out of scope:** Online payment processing, SMS gateways, and direct university SSO integration.
