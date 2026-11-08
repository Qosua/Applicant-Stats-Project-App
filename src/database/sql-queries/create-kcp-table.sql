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