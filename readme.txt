RHEIN
version 14.8.23
Application for Bentley MicroStation/OpenBuildings Designer
Main purpose: design of concrete reinforcement using 3D model
ATTENTION: Versions for MicroStation CONNECT are in BETA testing!

Features:
- reinforcement layout in 3D model
- clash detection on fly
- 2D drawings from 3D model
- specifications
- sketches

=================================================
Includes files:
REIN.DLL
REIN.MA
REIN.CFG
REIN.RSC
=================================================
Main key-Ins:
REIN MODIFY		: set or modify element properties
REIN FLAGS		: model elements presentation settings
REIN DUPS		: clashes recalculate
REIN LIST		: bars specification
REIN NOTE		: place or update note, tags to use: N1 - position number, Q1 - bars quantity, S1 - bars spacing, also N2, Q2, S2
REIN RELOAD		: model regeneration
REIN VERSION	: show program version
=================================================
How to install:
1. Copy REIN.MA, REIN.DLL into directory $(MS)MDLAPPS
2. Copy REIN.CFG into directory $(MS)CONFIG\APPL\
3. Copy REIN.RSC into directory included in variable MS_RSRCPATH
4. Load application by key-in MDL LOAD REIN
=================================================
Configuration variables: see file REIN.CFG
=================================================
Copyright 2024 Leonid Wiebe, All Rights Reserved.
St.Petersburg, Russia, mailto:wleo@ya.ru
=================================================

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

=================================================
