CREATE TABLE IF NOT EXISTS "columns_mapping" (
     "id" INTEGER NOT NULL,
     "entry_commision_id" INTEGER NOT NULL,
     "unique_code" TEXT NOT NULL,
     "score" TEXT NOT NULL,
     "achivments_score" TEXT NOT NULL,
     "subject_one" TEXT NOT NULL,
     "subject_two" TEXT NOT NULL,
     "subject_three" TEXT NOT NULL,
     "priority_number" TEXT NOT NULL,
     "consent" TEXT NOT NULL,
     "competition_group" TEXT NOT NULL,
     "phone_number" TEXT,
     "email" TEXT,
     "FIO" TEXT,
     "BVI" TEXT NOT NULL,
     "faculty_name" TEXT NOT NULL,
     "isAttended" TEXT NOT NULL,
     PRIMARY KEY("id")
--     FOREIGN KEY ("entry_commision_id") REFERENCES "entry_commisions"("id")
--     ON UPDATE CASCADE ON DELETE CASCADE
);