select *
from kcp
where entry_commision_id = (select id
                            from entry_commisions
                            where uni_name = :name and
                                is_bachelor = :isBachelor and
                                year = :year
);