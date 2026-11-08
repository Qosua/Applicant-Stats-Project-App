select unique_code, score, achivments_score, subject_one, subject_two, subject_three, priority_number, consent, competition_group, phone_number, email, FIO, BVI, faculty_name, isAttended
from columns_mapping
where entry_commision_id = (select id
                            from entry_commisions
                            where uni_name = :name and
                                is_bachelor = :isBachelor and
                                year = :year
);