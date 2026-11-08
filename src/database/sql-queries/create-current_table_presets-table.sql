CREATE TABLE IF NOT EXISTS "current_table_presets" (
    "id" INTEGER NOT NULL,
    "tableName" TEXT NOT NULL,
    "entry_commision_id" TEXT NULL,
    PRIMARY KEY("id"),
    CONSTRAINT "current_table_presets_unique_0" UNIQUE ("entry_commision_id", "tableName")
    --FOREIGN KEY ("entry_commision_id") REFERENCES "entry_commisions"("id")
    --ON UPDATE CASCADE ON DELETE CASCADE
);