#ifdef ADOPT_LUNA
void render_luna(int LUNA_X, int LUNA_Y);

/* KEYBOARD PET VARS START */
int   current_wpm;
led_t led_usb_state;

/* timers */
uint32_t anim_timer;

/* current frame */
uint8_t current_frame;

bool isSneaking;
bool isJumping;
bool showedJump;
/* KEYBOARD PET VARS END */

#endif
