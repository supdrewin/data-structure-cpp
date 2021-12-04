/** console_codes.hpp -*- C++ -*- Copyright (C) 2021 Supdrewin
 * This file is part of the Data Structure Cpp Project.
 * This Cpp project is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * This Cpp project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __console_codes_hpp
#define __console_codes_hpp 1

// Control characters

// beeps
#define BEL '\x07'

// backspaces one column (but not past the
// beginning of the line)
#define BS '\x08'

// goes to the next tab stop or to the end of
// the line if there is no earlier tab stop
#define HT '\x09'

// all give a linefeed, and if LF/NL (new-line
// mode) is set also a carriage return
#define LF '\x0a'
#define VT '\x0b'
#define FF '\x0c'

// gives a carriage return
#define CR '\x0d'

// activates the G1 character set
#define SO '\x0e'

// activates the G0 character set
#define SI '\x0f'

// abort escape sequences
#define CAN '\x18'
#define SUB '\x1a'

// starts an escape sequence
#define ESC '\x1b'

// is ignored
#define DEL '\x7f'

// ESC- but not CSI-sequences

// Reset.
#define RIS "\x1b\x63"

// Linefeed.
#define IND "\x1b\x44"

// Newline.
#define NEL "\x1b\x45"

// Set tab stop at current column.
#define HTS "\x1b\x48"

// Reverse linefeed.
#define RI "\x1b\x4d"

// DEC private identification. The kernel returns the
// string  ESC [ ? 6 c, claiming that it is a VT102.
#define DECID "\x1b\x5a"

// Save current state (cursor coordinates, attributes,
// character sets pointed at by G0, G1).
#define DECSD "\x1b\x37"

// Restore state most recently saved by ESC 7.
#define DECRD "\x1b\x38"

// Control sequence introducer
#define CSI "\x1b\x5b"

// DEC screen alignment test - fill screen with E's.
#define DECALN "\x1b\x23\x38"

// Set numeric keypad mode
#define DECPNM "\x1b\x3e"

// Set application keypad mode
#define DECPAM "\x1b\x3d"

// ECMA-48 CSI sequences
// TODO: Complete it!

// ECMA-48 Set Graphics Rendition

#define SGR_RESET_ALL "\x1b\x5b\x30\x6d"
#define SGR_BOLD "\x1b\x5b\x31\x6d"
#define SGR_HALF_BRIGHT "\x1b\x5b\x32\x6d"
#define SGR_UNDERSCORE "\x1b\x5b\x34\x6d"
#define SGR_BLINK_ON "\x1b\x5b\x35\x6d"
#define SGR_REVERSE_VIDEO_ON "\x1b\x5b\x37\x6d"
#define SGR_RESET_SELECTED "\x1b\x5b\x31\x30\x6d"

// TODO: Complete it!

#define SGR_UNDERLINE_ON "\x1b\x5b\x32\x31\x6d"
#define SGR_NORMAL_INTENSITY "\x1b\x5b\x32\x32\x6d"
#define SGR_UNDERLINE_OFF "\x1b\x5b\x32\x34\x6d"
#define SGR_BLINK_OFF "\x1b\x5b\x32\x35\x6d"
#define SGR_REVERSE_VIDEO_OFF "\x1b\x5b\x32\x37\x6d"

#define SGR_BLACK_FOREGROUND "\x1b\x5b\x33\x30\x6d"
#define SGR_RED_FOREGROUND "\x1b\x5b\x33\x31\x6d"
#define SGR_GREEN_FOREGROUND "\x1b\x5b\x33\x32\x6d"
#define SGR_BROWN_FOREGROUND "\x1b\x5b\x33\x33\x6d"
#define SGR_BLUE_FOREGROUND "\x1b\x5b\x33\x34\x6d"
#define SGR_MAGENTA_FOREGROUND "\x1b\x5b\x33\x35\x6d"
#define SGR_CYAN_FOREGROUND "\x1b\x5b\x33\x36\x6d"
#define SGR_WHITE_FOREGROUND "\x1b\x5b\x33\x37\x6d"

// TODO: Complete it!

#define SGR_BLACK_BACKGROUND "\x1b\x5b\x34\x30\x6d"
#define SGR_RED_BACKGROUND "\x1b\x5b\x34\x31\x6d"
#define SGR_GREEN_BACKGROUND "\x1b\x5b\x34\x32\x6d"
#define SGR_BROWN_BACKGROUND "\x1b\x5b\x34\x33\x6d"
#define SGR_BLUE_BACKGROUND "\x1b\x5b\x34\x34\x6d"
#define SGR_MAGENTA_BACKGROUND "\x1b\x5b\x34\x35\x6d"
#define SGR_CYAN_BACKGROUND "\x1b\x5b\x34\x36\x6d"
#define SGR_WHITE_BACKGROUND "\x1b\x5b\x34\x37\x6d"

// ECMA-48 Mode Switches
// TODO: Complete it!

#endif // !__console_codes_hpp
