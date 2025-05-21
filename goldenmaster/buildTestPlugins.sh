
#! /bin/bash
set -x;
export script_path="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )";
echo Script is in $script_path

# Check for UAT
RunUAT_path=`type -P RunUAT.sh`
if [ -z "$RunUAT_path" ]
then
	echo RunUAT.sh needs to be in the PATH environment variable
	exit 1
else
	echo RunUAT.sh found at ${RunUAT_path:0:-10}
fi

# Retrive UE path and test for plugins folder
UE_path=${RunUAT_path:0:-27}
if [ -d "$UE_path" ]
then
	echo "UE installation found at $UE_path"
else
	echo "Was not able to find UE installation at $UE_path"
	exit 1
fi

ProjectTarget_path=$script_path/TP_Blank
UEtemplate_path=${UE_path:0:-7}/Templates/TP_Blank
if [ -d "$UEtemplate_path" ]
then
	echo UE blank project template found at $UEtemplate_path
else
	echo Was not able to find UE blank project template $UEtemplate_path
	exit 1
fi

mkdir -p $ProjectTarget_path
if [ $? -ne 0 ]; then exit 1; fi;

echo Copy blank project from $UEtemplate_path to $script_path
cp -rf "$UEtemplate_path" "$script_path/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;
#
# function implementations
#

# build and test plugins
buildTestPlugins()
{
	# do not use -unattended as this seems to cause some issue when exiting the editor after test run
	"$RunUAT_path" BuildCookRun -installed -project="$1" -run -RunAutomationTest="$3" -nullrhi -NoP4 -build -verbose -nodebuginfo -log="$2/RunTests.log" -addcmdline="-ReportExportPath=$2 " -Configuration=Test -notools -utf8output
	buildresult=$?
}

#
# main
#

# copy ApiGear plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/ApiGear" &&  cp -rf "$script_path/Plugins/ApiGear" "$ProjectTarget_path/Plugins/ApiGear" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy Testbed2 plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/Testbed2" && cp -rf "$script_path/Plugins/Testbed2" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbEnum plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbEnum" && cp -rf "$script_path/Plugins/TbEnum" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbSame1 plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbSame1" && cp -rf "$script_path/Plugins/TbSame1" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbSame2 plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbSame2" && cp -rf "$script_path/Plugins/TbSame2" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbSimple plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbSimple" && cp -rf "$script_path/Plugins/TbSimple" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy Testbed1 plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/Testbed1" && cp -rf "$script_path/Plugins/Testbed1" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbNames plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbNames" && cp -rf "$script_path/Plugins/TbNames" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy CustomTypes plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/CustomTypes" && cp -rf "$script_path/Plugins/CustomTypes" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy ExternTypes plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/ExternTypes" && cp -rf "$script_path/Plugins/ExternTypes" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy Counter plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/Counter" && cp -rf "$script_path/Plugins/Counter" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbRefInterfaces plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbRefInterfaces" && cp -rf "$script_path/Plugins/TbRefInterfaces" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbRefInterfacesImport plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbRefInterfacesImport" && cp -rf "$script_path/Plugins/TbRefInterfacesImport" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


buildTestPlugins "$ProjectTarget_path/TP_Blank.uproject" "$script_path" ".Impl.+.OLink.+.MsgBus."
if [ $buildresult -ne 0 ]; then exit 1; fi;
