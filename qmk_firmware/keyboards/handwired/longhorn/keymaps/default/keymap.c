#include QMK_KEYBOARD_H

enum custom_keycodes {
    VI_BYE  = SAFE_RANGE,
    VI_SAVE = SAFE_RANGE+1, 
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // MACROS to help with VI painful finger gymnastic
        case VI_BYE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) ":q!\n");
            }
            break;
        case VI_SAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) ":x!\n");
            }
            break;
    }
    return true;
};

// Layers
enum kb_layers {
  _DVORAK,   // 0
  _SYMBOLS,  // 1
  _FUNCTION, // 2
  _QWERTY,   // 3
};

// Layer keys
const uint16_t PROGMEM L1      = LT(1, KC_SPC);   // Layer1, or space
const uint16_t PROGMEM L2      = LT(2, KC_NO);   // L2, activate func layers
const uint16_t PROGMEM TOG_3   = TG(3);          // toggle qwerty layer

// Modifier Taps
const uint16_t PROGMEM CTL_Q   = LCTL_T(KC_Q);    // Control when held, Q otherwise
const uint16_t PROGMEM ALT_J   = LALT_T(KC_J);    // Alt or J
const uint16_t PROGMEM CMD_K   = LGUI_T(KC_K);    // Command or K
const uint16_t PROGMEM CMD_M   = RGUI_T(KC_M);    // Command or M
const uint16_t PROGMEM ALT_W   = RALT_T(KC_W);    // Alt or W
const uint16_t PROGMEM CTL_V   = RCTL_T(KC_V);    // Command or V
const uint16_t PROGMEM SFT_U   = LSFT_T(KC_U);    // Shift or U
const uint16_t PROGMEM SFT_H   = RSFT_T(KC_H);    // Shift or H

// Shortcuts
const uint16_t PROGMEM WIN_LEFT  = LGUI(LALT(KC_LEFT));  // Spectacle, window to left
const uint16_t PROGMEM WIN_RGHT  = LGUI(LALT(KC_RGHT));  // Spectacle, window to right
const uint16_t PROGMEM SCR_SHOT  = SGUI(KC_4);           // Screnshot
const uint16_t PROGMEM UNDO      = LGUI(KC_Z);
const uint16_t PROGMEM REDO      = LSFT(LGUI(KC_Z));
const uint16_t PROGMEM CUT       = LGUI(KC_X);
const uint16_t PROGMEM COPY      = LGUI(KC_C);
const uint16_t PROGMEM PASTE     = LGUI(KC_V);
const uint16_t PROGMEM LOGOUT    = LCTL(LGUI(KC_Q)); 
const uint16_t PROGMEM HOME      = LCTL(KC_A);
const uint16_t PROGMEM _END       = LCTL(KC_E);
const uint16_t PROGMEM SFT_BR     = LSFT_T(KC_LBRC);         // Shift or [
const uint16_t PROGMEM SFT_RBR    = LSFT_T(KC_RBRC);         // Shift or ]
const uint16_t PROGMEM CTL_ESC    = LCTL_T(KC_ESC);          // Ctl or Esc
const uint16_t PROGMEM D_EOL      = LCTL(KC_K);              // delete to end of line
const uint16_t PROGMEM D_SOL      = LCTL(KC_U);              // delete to start of line

// Layout for My custom "longhorn" keyboard. Thibaut Colar.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Dvorak (alpha & ponctuation).
    // :, `, =, ?, - and / are also available on this layer as I use them frequently.
    // Modifiers (CMD, CTL, ALT) are on strongest fingers, but on lower row to avoid misfires when typing fast (rolling), 
    // q, j ,k, m, w, v are almost never seen consecutively in English, so no modifier misfires.
    // Top row is used for shortcuts and parentheses
    // Arrows on thumb keys are useful because many shortcuts using arrows.
    //
    // ------------------------------------------------------------            ------------------------------------------------------------
    // |  Caps  |    `    |    {    |    (    |    [    |  Undo   |            |  Redo  |    ]    |    )    |    }    |    =    | Toggle1 |
    // |--------|---------|---------|---------|-------------------|            |--------|---------|---------|---------|---------|---------| 
    // |   Esc  |   ' "   |   , <   |   . >   |    P    |    Y    |            |   F    |    G    |    C    |    R    |    L    |    ?    | 
    // |--------|---------|---------|--------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |   Tab  |    A    |    O    |    E   |Shift / U |    I    |            |   D    |Shift / H|    T    |    N    |    S    |    -    | 
    // |--------|---------|---------|--------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |   :    |   ; :   | Ctrl / Q| Alt / J| Cmd / K  |   X     |            |   B    | Cmd / M | Alt / W | Ctl / V |    Z    |    /    | 
    // ---------|---------|---------|--------|--------------------|            |--------|---------|---------|---------|---------|---------|
    //          | Bkspc   | L1/SPC  |  Del   |     Up   |  Down   |            |  Left  |   Right |  L2     |  L1/SPC |  Enter  |
    //          ---------------------------------------------------            --------------------------------------------------
    [_DVORAK] = LAYOUT(
        KC_CAPS , KC_GRV  , KC_LCBR , KC_LPRN , KC_LBRC , UNDO          ,        REDO  , KC_RBRC , KC_RPRN , KC_RCBR , KC_EQL  , TG(1),
        KC_ESC  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y          ,        KC_F  , KC_G    , KC_C    , KC_R    , KC_L    , KC_QUES , 
        KC_TAB  , KC_A    , KC_O    , KC_E    , SFT_U   , KC_I          ,        KC_D  , SFT_H   , KC_T    , KC_N    , KC_S    , KC_MINS , 
        KC_COLN , KC_SCLN , CTL_Q   , ALT_J   , CMD_K   , KC_X          ,        KC_B  , CMD_M   , ALT_W   , CTL_V   , KC_Z    , KC_PSLS, 
                  KC_BSPC ,  L1     , KC_DEL  , KC_UP   , KC_DOWN       ,      KC_LEFT , KC_RGHT ,    L2   ,   L1    , KC_ENT),

    // Numbers and math symbols on right (Numbers are top to bottom, standard numpads make little sense to me).
    // Nav keys on left, "WASD style".
    // Rest of programming symbols on left as well. 
    //
    // -------------------------------------------------------------           ------------------------------------------------------------
    // | Logout | WinLeft |         | Page Up |         | Vi bye   |           |Vi save |         | ScrShot |         | WinRight| Toggle1 |
    // |--------|---------|---------|---------|--------------------|           |--------|---------|---------|---------|---------|---------| 
    // |  Esc   |    `    |    $    |    Up   |    &    |    |     |           |   0    |    1    |    2    |    3    |    %    |    ^    | 
    // |--------|---------|---------|---------|--------------------|           |--------|---------|---------|---------|---------|---------| 
    // |   ~    |    @    |   Left  |   Down  |  Right  |    !     |           |   ,    |    4    |    5    |    6    |    +    |    -    | 
    // |--------|---------|---------|---------|--------------------|           |--------|---------|---------|---------|---------|---------| 
    // |        |    :    |    #    | Page Dn |    \    |    =     |           |   .    |    7     |   8    |    9    |    *    |    /    | 
    // ---------|---------|---------|---------|--------------------|           |--------|---------|---------|---------|---------|---------|
    //          | D_SOL   |  L1     |  D_EOL  |         |          |           |  HOME  |   END   |  TOG_3  |  L1     |         |
    //          ----------------------------------------------------           --------------------------------------------------
    [_SYMBOLS] = LAYOUT(
        LOGOUT  , WIN_LEFT, KC_NO   , KC_PGUP , KC_NO   , VI_BYE         ,      VI_SAVE , KC_NO    , SCR_SHOT, KC_NO  , WIN_RGHT, KC_TRNS , 
        KC_TRNS , KC_GRV  , KC_DLR  , KC_UP   , KC_AMPR , KC_PIPE        ,      KC_0    , KC_1     , KC_2    , KC_3   , KC_PERC , KC_CIRC , 
        KC_TILD , KC_AT   , KC_LEFT , KC_DOWN , KC_RGHT , KC_EXLM        ,      KC_COMM , KC_4     , KC_5    , KC_6   , KC_PLUS , KC_MINS ,
        KC_TRNS , KC_COLN , KC_HASH , KC_PGDN , KC_BSLS , KC_EQL         ,      KC_DOT  , KC_7     , KC_8    , KC_9   , KC_ASTR , KC_SLSH ,
                  D_SOL   , KC_TRNS , D_EOL   ,  KC_NO  , KC_NO          ,      HOME    ,   _END   , TOG_3  ,  L1     , KC_TRNS),

    // Function keys, Mouse nav, volume, LEDs, and other rarely used keys.
    //
    // -------------------------------------------------------------            ------------------------------------------------------------
    // |  F1    |    F2   |    F3   |    F4   |    F5   |    F6    |            |   F7   |    F8   |    F9   |   F10   |   F11   |   F12   |
    // |--------|---------|---------|---------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |        | M W Up  |         |  M Up   |         |   Vol+   |            | RgbMod+| Bright+ |         |         |  Insert | Delete  | 
    // |--------|---------|---------|---------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |        | M W Dn  | M Left  |  M Dn   | M Right |   Vol-   |            | RgbMod-| Bright- |         |         |  Eject  |  Pause  | 
    // |--------|---------|---------|---------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |        |         |   M 1   |   M 2   |   M 3   |   Mute   |            | RbgTog |         |         |         |  PrtScr |  Scroll | 
    // ---------|---------|---------|---------|--------------------|            |--------|---------|---------|---------|---------|---------|
    //          |         |         |         |         |          |            |        |         |         |         |  RESET  |
    //          ----------------------------------------------------            --------------------------------------------------
    [_FUNCTION] = LAYOUT(
        KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6          ,        KC_F7  , KC_F8    , KC_F9   , KC_F10 , KC_F11  , KC_F12, 
        KC_NO   , KC_WH_U , KC_NO   , KC_MS_U , KC_NO   , KC_VOLU        ,       RGB_MOD , KC_BRIU  , KC_NO   , KC_NO  , KC_INS  , KC_DEL,
        KC_NO   , KC_WH_D , KC_MS_L , KC_MS_D , KC_MS_R , KC_VOLD        ,       RGB_RMOD, KC_BRID  , KC_NO   , KC_NO  , KC_EJCT , KC_PAUS, 
        KC_NO   , KC_NO   , KC_BTN1 , KC_BTN2 , KC_BTN3 , KC_MUTE        ,       RGB_TOG , KC_NO    , KC_NO   , KC_NO  , KC_PSCR , KC_SLCK, 
                  KC_NO   , KC_NO   , KC_NO   ,  KC_NO  , KC_NO          ,        KC_NO  , KC_NO    , KC_NO   , KC_NO  , RESET),

    // Gaming layout ...
    //
    // -------------------------------------------------------------             ------------------------------------------------------------
    // |  Caps  |     1   |    2    |    3    |    4    |    5     |             |   6    |    7    |    8    |   9     |    0    | TOG3    |
    // |--------|---------|---------|---------|--------------------|             |--------|---------|---------|---------|---------|---------| 
    // |  Tab   |     T   |    Q    |    R    |    E     |   X     |             | ESC    |    '    |   UP    |    /    |  PG_UP  |  VOL+   | 
    // |--------|---------|---------|---------|--------------------|             |--------|---------|---------|---------|---------|---------| 
    // |  M     |     G   |    A    |    W    |    D     |   F     |             |  `     |   LEFT  |   Dn    |   Right |  PG_DN  |  VOL-   | 
    // |--------|---------|---------|---------|--------------------|             |--------|---------|---------|---------|---------|---------| 
    // |  I     |     B   |    Z    |    S    |    C     |   V     |             |  Y     |   N     |   K     |    +    |   -     |   =     | 
    // ---------|---------|---------|---------|--------------------|             |--------|-------- |---------|---------|---------|---------|
    //          |     H   |  Shift  |   Space |    CTRL  |   U     |             |  ALT   |  WIN    | BackSpc |  DEL    |  ENTER  |
    //          ----------------------------------------------------             --------------------------------------------------
    [_QWERTY] = LAYOUT(
        KC_CAPS , KC_1    , KC_2    , KC_3    , KC_4    , KC_5           ,          KC_6  , KC_7    , KC_8    , KC_9    , KC_0    , TOG_3 , 
        KC_TAB  , KC_T    , KC_Q    , KC_R    , KC_E    , KC_X           ,         KC_ESC , KC_QUOT , KC_UP   , KC_PSLS , KC_PGUP , KC_VOLU, 
        KC_M    , KC_G    , KC_A    , KC_W    , KC_D    , KC_F           ,          KC_GRV, KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN , KC_VOLD, 
        KC_I    , KC_B    , KC_Z    , KC_S    , KC_C    , KC_V           ,          KC_Y  , KC_N    , KC_K    , KC_PLUS , KC_MINS , KC_EQL, 
                  KC_H    , KC_LSFT , KC_SPC  , KC_LCTL , KC_U           ,        KC_LALT , KC_LGUI , KC_BSPC , KC_DEL  , KC_ENT )
};
