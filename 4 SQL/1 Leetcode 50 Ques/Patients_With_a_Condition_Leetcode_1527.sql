
/*

Patients_With_a_Condition_Leetcode_1527

Table: Patients

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
patient_id is the primary key (column with unique values) for this table.
'conditions' contains 0 or more code separated by spaces. 
This table contains information of the patients in the hospital.
 

Write a solution to find the patient_id, patient_name, and conditions of the patients who have Type I Diabetes. Type I Diabetes always starts with DIAB1 prefix.
Return the result table in any order.

The result format is in the following example.

        Example 1:

        Input: 
        Patients table:
        +------------+--------------+--------------+
        | patient_id | patient_name | conditions   |
        +------------+--------------+--------------+
        | 1          | Daniel       | YFEV COUGH   |
        | 2          | Alice        |              |
        | 3          | Bob          | DIAB100 MYOP |
        | 4          | George       | ACNE DIAB100 |
        | 5          | Alain        | DIAB201      |
        +------------+--------------+--------------+
        Output: 
        +------------+--------------+--------------+
        | patient_id | patient_name | conditions   |
        +------------+--------------+--------------+
        | 3          | Bob          | DIAB100 MYOP |
        | 4          | George       | ACNE DIAB100 | 
        +------------+--------------+--------------+
        Explanation: Bob and George both have a condition that starts with DIAB1.

*/


/*
Approach : 
The question is asking to include conditions that start with DIAB1.
'%DIAB1%' will return any string that contain DIAB1 in the middle which is not reuqired. 
for example if the condition is ABCDIAB1 it will be included in the results which is wrong.
*/

select
patient_id,
patient_name,
conditions
from Patients
where conditions like '% DIAB1%' or conditions like 'DIAB1%';