INSERT INTO current_table_presets (tableName, entry_commision_id)
VALUES (:tableName, :entry_commision_id)
ON CONFLICT(entry_commision_id, tableName) DO NOTHING;