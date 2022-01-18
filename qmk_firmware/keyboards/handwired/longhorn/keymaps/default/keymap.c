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
#define L1     LT(1, KC_SPC)  // Layer1, or space
#define L2     LT(2, KC_NO)   // L2, activate func layers
#define TOG_3  TG(3)          // toggle qwerty layer

// Modifier Taps
#define CTL_Q   LCTL_T(KC_Q)    // Control when held, Q otherwise
#define SFT_U   LSFT_T(KC_U)    // Shift or U
#define ALT_J   LALT_T(KC_J)    // Alt or J
#define CMD_K   LGUI_T(KC_K)    // Command or K
#define CMD_M   RGUI_T(KC_M)    // Command or M
#define ALT_W   RALT_T(KC_W)    // Alt or W
#define CTL_V   RCTL_T(KC_V)    // Command or V
#define SFT_H   RSFT_T(KC_H)    // Shift or H
#define SFT_SPC LSFT_T(KC_SPC)  // Shift or Space

// Shortcuts
#define WIN_LEFT LGUI(LALT(KC_LEFT))  // Spectacle, window to left
#define WIN_RGHT LGUI(LALT(KC_RGHT))  // Spectacle, window to right
#define SCR_SHOT SGUI(KC_4)           // Screnshot
#define UNDO     LGUI(KC_Z)
#define REDO     LSFT(LGUI(KC_Z))
#define CUT      LGUI(KC_X)
#define COPY     LGUI(KC_C)
#define PASTE    LGUI(KC_V)
#define LOGOUT   LCTL(LGUI(KC_Q)) 
#define HOME     LCTL(KC_A)
#define _END     LCTL(KC_E)
#define SFT_BR   LSFT_T(KC_LBRC)         // Shift or [
#define SFT_RBR  LSFT_T(KC_RBRC)         // Shift or ]
#define CTL_ESC  LCTL_T(KC_ESC)          // Ctl or Esc
#define D_EOL    LCTL(KC_K)              // delete to end of line
#define D_SOL    LCTL(KC_U)              // delete to start of line
#define LOWER    LSFT(KC_COMMA)          // <
#define GREATER  LSFT(KC_DOT)            // >
#define DBLQUOT  LSFT(KC_QUOT)           // "

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
    // |  Esc   |    1    |    2    |    3    |    4    |    5    |            |   6    |   7     |    8    |   9     |    0    | CAPS    |
    // |--------|---------|---------|---------|-------------------|            |--------|---------|---------|---------|---------|---------| 
    // |   "    |   ' "   |   , <   |   . >   |    P    |    Y    |            |   F    |    G    |    C    |    R    |    L    |    ?    | 
    // |--------|---------|---------|--------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |   Tab  |    A    |    O    |    E   |Shift / U |    I    |            |   D    |Shift / H|    T    |    N    |    S    |    -    | 
    // |--------|---------|---------|--------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |   :    |   ; :   | Ctrl / Q| Alt / J| Cmd / K  |   X     |            |   B    | Cmd / M | Alt / W | Ctl / V |    Z    |    /    | 
    // ---------|---------|---------|--------|--------------------|            |--------|---------|---------|---------|---------|---------|
    //          | Bkspc   | SFT/SPC |  Del   |   UNDO   |  REDO   |            | VI_BYE | VI_SAVE |  L2     | L1/SPC  |  Enter  |
    //          ---------------------------------------------------            --------------------------------------------------
    [_DVORAK] = LAYOUT(
        KC_ESC  , KC_1    , KC_2    , KC_3   , KC_4     , KC_5          ,       KC_6   , KC_7    , KC_8    , KC_9    , KC_0    , KC_CAPS ,
        DBLQUOT , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y          ,        KC_F  , KC_G    , KC_C    , KC_R    , KC_L    , KC_QUES , 
        KC_TAB  , KC_A    , KC_O    , KC_E    , SFT_U   , KC_I          ,        KC_D  , SFT_H   , KC_T    , KC_N    , KC_S    , KC_MINS , 
        KC_COLN , KC_SCLN , CTL_Q   , ALT_J   , CMD_K   , KC_X          ,        KC_B  , CMD_M   , ALT_W   , CTL_V   , KC_Z    , KC_SLSH, 
                  KC_BSPC , SFT_SPC , KC_DEL  , UNDO    , REDO          ,       VI_BYE , VI_SAVE ,    L2   , L1      , KC_ENT),

    // Numbers and math symbols on right (Numbers are top to bottom, standard numpads make little sense to me).
    // Nav keys on left, "WASD style".
    // Rest of programming symbols on left as well. 
    //
    // -------------------------------------------------------------           ------------------------------------------------------------
    // | Logout | WinLeft |         |         |         |          |           |        |         | ScrShot |         | WinRight|  TOG_3  |
    // |--------|---------|---------|---------|--------------------|           |--------|---------|---------|---------|---------|---------| 
    // |  Esc   |    `    |   <     |    >    |    [    |    ]     |           |  D_SOL |    =    |    *    |  D_EOL  |    %    |    ^    | 
    // |--------|---------|---------|---------|--------------------|           |--------|---------|---------|---------|---------|---------| 
    // |   ~    |    @    |   {     |   }     |    (    |    )     |           |  Left  |  Down   |    Up   |  Right  |    +    |    -    | 
    // |--------|---------|---------|---------|--------------------|           |--------|---------| --------|---------|---------|---------| 
    // |   :    |    #    |   $     |   &     |    |    |    !     |           |  Home  | Pg Dn   |  Pg Up  |  End    |    \    |    /    | 
    // ---------|---------|---------|---------|--------------------|           |--------|---------|---------|---------|---------|---------|
    //          |         |         |         |         |          |           |        |         |  TOG_3  |         |         |
    //          ----------------------------------------------------           --------------------------------------------------
    [_SYMBOLS] = LAYOUT(
        LOGOUT  , WIN_LEFT, KC_NO   ,   KC_NO ,   KC_NO , KC_NO          ,      KC_NO   , KC_NO    , SCR_SHOT, KC_NO  , WIN_RGHT, TOG_3 , 
        KC_TRNS , KC_GRV  , LOWER   , GREATER , KC_LBRC , KC_RBRC        ,      D_SOL   , KC_EQL   , KC_ASTR , D_EOL  , KC_PERC , KC_CIRC , 
        KC_TILD , KC_AT   , KC_LCBR , KC_RCBR , KC_LPRN , KC_RPRN        ,      KC_LEFT , KC_DOWN  , KC_UP   , KC_RGHT, KC_PLUS , KC_MINS ,
        KC_COLN , KC_HASH , KC_DLR  , KC_AMPR , KC_PIPE , KC_EXLM        ,      HOME    , KC_PGDN  , KC_PGUP , _END   , KC_BSLS , KC_SLSH ,
                  KC_NO   , KC_TRNS , KC_NO   , KC_NO   , KC_NO          ,      KC_NO   , KC_NO    , TOG_3   , KC_TRNS, KC_TRNS),

    // Function keys, Mouse nav, volume, LEDs, and other rarely used keys.
    //
    // -------------------------------------------------------------            ------------------------------------------------------------
    // |  F1    |    F2   |    F3   |    F4   |    F5   |    F6    |            |   F7   |    F8   |    F9   |   F10   |   F11   |   F12   |
    // |--------|---------|---------|---------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |        |         |         | Bright+ | RgbMod+ |   Vol+   |            |        | M 1     |  M 2    |         |  Insert | Delete  | 
    // |--------|---------|---------|---------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |        |         |         | Bright- | RgbMod- |   Vol-   |            | M Left | M Down  |  M Up   | M Right |  Eject  |  Pause  | 
    // |--------|---------|---------|---------|--------------------|            |--------|---------|---------|---------|---------|---------| 
    // |        |         |         |         | RbgTog  |   Mute   |            |        | M W Dn  | M W Up  |         |  PrtScr |  Scroll | 
    // ---------|---------|---------|---------|--------------------|            |--------|---------|---------|---------|---------|---------|
    //          |         |         |         |         |          |            |        |         |         |         |  RESET  |
    //          ----------------------------------------------------            --------------------------------------------------
    [_FUNCTION] = LAYOUT(
        KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6          ,        KC_F7  , KC_F8    , KC_F9   , KC_F10 , KC_F11  , KC_F12, 
        KC_NO   , KC_NO   , KC_NO   , KC_BRIU , RGB_MOD , KC_VOLU        ,       KC_NO   , KC_BTN1  , KC_BTN2 , KC_NO  , KC_INS  , KC_DEL,
        KC_NO   , KC_NO   , KC_NO   , KC_BRID , RGB_RMOD, KC_VOLD        ,       KC_MS_L , KC_MS_D  , KC_MS_U , KC_MS_R, KC_EJCT , KC_PAUS, 
        KC_NO   , KC_NO   , KC_NO   , KC_NO   , RGB_TOG , KC_MUTE        ,       KC_NO   , KC_WH_U  , KC_WH_D , KC_NO  , KC_PSCR , KC_SLCK, 
                  KC_NO   , KC_NO   , KC_NO   ,  KC_NO  , KC_NO          ,       KC_NO   , KC_NO    , KC_NO   , KC_NO  , RESET),

    // Gaming layout ...
    //
    // -------------------------------------------------------------             ------------------------------------------------------------
    // |  Esc   |     1   |    2    |    3    |    4    |    5     |             |   6    |    7    |    8    |   9     |    0    | TOG3    |
    // |--------|---------|---------|---------|--------------------|             |--------|---------|---------|---------|---------|---------| 
    // |  Tab   |    T    |    Q    |    x    |    E     |   R     |             |   Y    |    U    |   UP    |    /    |  PG_UP  |  VOL+   | 
    // |--------|---------|---------|---------|--------------------|             |--------|---------|---------|---------|---------|---------| 
    // |  Caps  |  I      |    A    |    W    |    D     |   F     |             |   G    |   LEFT  |   Dn    |   Right |  PG_DN  |  VOL-   | 
    // |--------|---------|---------|---------|--------------------|             |--------|---------|---------|---------|---------|---------| 
    // |   J    |     H   |    Z    |    S    |    C     |   V     |             |   B    |   N     |   M     |    +    |   -     |   =     | 
    // ---------|---------|---------|---------|--------------------|             |--------|-------- |---------|---------|---------|---------|
    //          |  Ctrl   | Shift   |   Space |    Enter |  Alt    |             |  K     |  WIN    | BackSpc |  DEL    |  L      |
    //          ----------------------------------------------------             --------------------------------------------------
    [_QWERTY] = LAYOUT(
        KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5           ,          KC_6  , KC_7    , KC_8    , KC_9    , KC_0    , TOG_3 , 
        KC_TAB  , KC_T    , KC_Q    , KC_X    , KC_E    , KC_R           ,         KC_Y   , KC_U    , KC_UP   , KC_PSLS , KC_PGUP , KC_VOLU, 
        KC_CAPS , KC_I    , KC_A    , KC_W    , KC_D    , KC_F           ,          KC_G  , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN , KC_VOLD, 
        KC_J    , KC_H    , KC_Z    , KC_S    , KC_C    , KC_V           ,          KC_B  , KC_N    , KC_M    , KC_PLUS , KC_MINS , KC_EQL, 
                  KC_LCTL , KC_LSFT , KC_SPC  , KC_ENTER, KC_LALT        ,        KC_K    , KC_LGUI , KC_BSPC , KC_DEL  , KC_L )
};
