
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
    PRIMARY KEY("id"),
    FOREIGN KEY ("entry_commision_id") REFERENCES "entry_commisions"("id")
    ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "entry_commisions" (
    "id" INTEGER NOT NULL,
    "uni_name" TEXT NOT NULL,
    "is_bachelor" boolean NOT NULL,
    "year" INTEGER NOT NULL,
    PRIMARY KEY("id"),
    CONSTRAINT "entry_commisions_unique_0" UNIQUE ("uni_name", "is_bachelor", "year")
);

CREATE TABLE IF NOT EXISTS "kcp" (
    "id" INTEGER NOT NULL,
    "entry_commision_id" INTEGER NOT NULL,
    "code" TEXT NOT NULL,
    "department" TEXT NOT NULL,
    "profile_name" TEXT NOT NULL,
    "study_form" INTEGER NOT NULL,
    "study_type" INTEGER NOT NULL,
    "kcp_count" INTEGER NOT NULL,
    PRIMARY KEY("id"),
    CONSTRAINT "kcp_unique_0" UNIQUE ("entry_commision_id", "code", "department", "profile_name", "study_form", "study_type")
    --FOREIGN KEY ("entry_commision_id") REFERENCES "entry_commisions"("id")
    --ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "current_table_presets" (
    "id" INTEGER NOT NULL,
    "tableName" TEXT NOT NULL,
    "entry_commision_id" TEXT NULL,
    PRIMARY KEY("id"),
    CONSTRAINT "current_table_presets_unique_0" UNIQUE ("entry_commision_id", "tableName")
    --FOREIGN KEY ("entry_commision_id") REFERENCES "entry_commisions"("id")
    --ON UPDATE CASCADE ON DELETE CASCADE
);


CREATE INDEX IF NOT EXISTS idx_kcp_commision ON kcp(entry_commision_id);

CREATE INDEX IF NOT EXISTS idx_columns_mapping_commision ON columns_mapping(entry_commision_id);

