CREATE TABLE IF NOT EXISTS "entry_commisions" (
      "id" INTEGER NOT NULL,
      "uni_name" TEXT NOT NULL,
      "is_bachelor" boolean NOT NULL,
      "year" INTEGER NOT NULL,
      PRIMARY KEY("id"),
      CONSTRAINT "entry_commisions_unique_0" UNIQUE ("uni_name", "is_bachelor", "year")
);