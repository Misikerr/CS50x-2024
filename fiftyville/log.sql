-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports
WHERE street = 'Humphrey Street';
--Bakery witnesses--
SELECT * FROM interviews
WHERE transcript LIKE '%bakery%';
--Witness 1 ruth--
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;
--check against license plates--
SELECT p.name, bsl.activity, bsl.license_plate, bsl.year, bsl.month, bsl.day, bsl.hour,bsl.minute
FROM bakery_security_logs bsl
JOIN people p ON p.license_plate = bsl.license_plate
WHERE bsl.year = 2021 AND bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 25;
--check witness 2 re: atm--
SELECT * FROM atm_transactions
WHERE atm_location = 'leggett Street'
AND year = 2021 AND month = 7 AND day = 28;
--add name of withdraws from atm--
SELECT a.*, p.name
FROM atm_transactions a
JOIN bank_accounts b ON a.account_number = b.account_number
JOIN people p ON b.person_id = p.id
WHERE a.atm_location = 'Leggett Street' AND a.year = 2021 AND a.month = 7 AND a.day = 28 AND a.transaction_type = 'withdraw';
 --Witness 3 phone call investigation--
 SELECT *
 FROM phone_calls
 WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
 --add names to call list of callers--
 SELECT p.name, pc.caller, pc.receiver, pc.year, pc.month, pc.day, pc duration
 FROM phone_calls pc
 JOIN people p ON pc.caller p.phone_number
 WHERE pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;
 --explore airport to find fiftyville--
 SELECT * FROM airports;
 --found fiftyville id(8) explore flights out--
 SELECT f.*, origin.full_name AS origin_airport , destination.full_name AS destination_airport
 FROM flights  f
 JOIN airports origin ON f.origin_airport_id = origin.id
 JOIN airports destination ON f.destination_airport_id = destination.id
 WHERE origin.id = 8 AND f.year = 2021 AND f.month = 7 AND f.day = 29
 ORDER BY f.hour, f.minute;
 --combine info from all three testimonies--
 SELECT p.name
 FROM bakery_security_logs bsl
 JOIN people p ON p.license_plate = bsl.license_plate
 JOIN bank_accounts ba ON ba.person_id = p.id
 JOIN atm_transactions at ON at.account_number = ba.account_number
 JOIN phone_calls pc ON pc.caller = p.phone_number
 WHERE bsl.year = 2021 AND bsl.month = 7 AND bsl.day = 28 AND bal.hour = 10 AND bsl.minute BETWEEN 15 AND 25
 AND at.atm_location = 'Leggett Street' AND at.year = 2021 AND at.day = 28 AND at.transaction_type ='withdraw'
 AND pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;
 -- Narrow down from bruce/diana who is on flight--
 SELECT p.name
 FROM people p
 JOIN passengers ps ON p.passport_number = ps.passport_number
 WHERE ps.flight_id = 36
 AND p.name IN ('Bruce', 'Diana');
 --who did bruce call--
SELECT p2.name AS receiver
FROM phone_callspc
JOIN people p1 ON pc.caller = p1.phone_number
JOIN people p2 ON pc.receiver = p2.phone_number
WHERE p1.name = 'Bruce' AND pc.year = 2021 AND pc.month = 7 AND pc.day = 28
