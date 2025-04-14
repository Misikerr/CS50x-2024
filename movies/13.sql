SELECT p.name FROM people p
 JOIN stars s ON p.id = s.person_id
 JOIN movies m ON s.movie_id = m.id
 WHERE m.id IN (
    SELECT m.id FROM movies m
    JOIN stars s ON m.id = s.movie_id
    JOIN people p ON s.person_id = p.id
    WHERE p.name = 'Kevin Bacon' AND p.birth = 1958
 )  AND p.name != 'Kevin Bacon';
