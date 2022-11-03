#!/bin/bash
python_version=$(python --version)
echo $python_version
IFS=' '
read -a python_version_arr <<< "$python_version"
python_version=${python_version_arr[1]}
IFS='.'
read -a python_version_arr <<< "$python_version"
if [[ "$((${python_version_arr[0]}))" == 3 ]] ; then
	if [[ "$((${python_version_arr[1]}))" -gt 9 ]] ; then
		IFS=''
		script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && (pwd -W 2> /dev/null || pwd))
		script_dir="${script_dir}/src/ProgrammerInterface/ProgrammerUI.py"
		echo $script_dir
		python $script_dir
	fi
fi
