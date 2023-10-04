#Script to launch the EEPROM programming tool
#Copyright (C) 2023  Tristan van de Weg & Marijn Vollenberg
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License along
#    with this program; if not, write to the Free Software Foundation, Inc.,
#    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#!/bin/bash
python_version=$(python --version)
echo $python_version
IFS=' '
read -a python_version_arr <<< "$python_version"
python_version=${python_version_arr[1]}
IFS='.'
read -a python_version_arr <<< "$python_version"
echo ${python_version_arr[0]}
echo ${python_version_arr[1]}
if [[ "$((${python_version_arr[0]}))" -gt 3 ]] ; then
	if [[ "$((${python_version_arr[1]}))" -gt 9 ]] ; then
		IFS=''
		script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && (pwd -W 2> /dev/null || pwd))
		script_dir="${script_dir}/src/ProgrammerInterface/programmer.py"
		echo $script_dir
		python $script_dir
	fi
fi
