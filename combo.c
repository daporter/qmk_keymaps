bool get_combo_must_tap(uint16_t index, combo_t *combo)
{
	// make every combo that has mod-tap/layer-tap/momentary keys in its
	// chord tap-only.
	uint16_t key;
	uint8_t idx = 0;
	while ((key = pgm_read_word(&combo->keys[idx])) != combo_end) {
		switch (key) {
		case QK_MOD_TAP ... QK_MOD_TAP_MAX:
		case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
		case QK_MOMENTARY ... QK_MOMENTARY_MAX:
			return true;
		}
		idx += 1;
	}
	return false;
}
