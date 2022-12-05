function bv_fides_initialize
{
    export DO_FIDES="no"
}

function bv_fides_enable
{
    DO_FIDES="yes"
}

function bv_fides_disable
{
    DO_FIDES="no"
}

function bv_fides_depends_on
{
    local depends_on="vtkm"

    echo ${depends_on}
}

function bv_fides_info
{
    export FIDES_VERSION=${FIDES_VERSION:-"1.1.0"}
    export FIDES_FILE=${FIDES_FILE:-"fides-v${FIDES_VERSION}.tar.gz"}
    export FIDES_BUILD_DIR=${FIDES_BUILD_DIR:-"fides-v${FIDES_VERSION}"}
    export FIDES_URL=${FIDES_URL:-"https://gitlab.kitware.com/vtk/fides/-/archive/v1.1.0/"}
    export FIDES_MD5_CHECKSUM="358857f37d3fb2be1f878d934b8e7c39"
    export FIDES_SHA256_CHECKSUM="40d2e08b8d5cfdfc809eae6ed2ae0731108ce3b1383485f4934a5ec8aaa9425e"
}

function bv_fides_print
{
    printf "%s%s\n" "FIDES_FILE=" "${FIDES_FILE}"
    printf "%s%s\n" "FIDES_VERSION=" "${FIDES_VERSION}"
    printf "%s%s\n" "FIDES_BUILD_DIR=" "${FIDES_BUILD_DIR}"
}

function bv_fides_print_usage
{
    printf "%-20s %s [%s]\n" "--fides" "Build Fides support" "$DO_FIDES"
}

function bv_fides_host_profile
{
    if [[ "$DO_FIDES" == "yes" ]] ; then
        echo >> $HOSTCONF
        echo "##" >> $HOSTCONF
        echo "## FIDES " >> $HOSTCONF
        echo "##" >> $HOSTCONF
        echo \
            "VISIT_OPTION_DEFAULT(VISIT_FIDES_DIR \${VISITHOME}/fides/$FIDES_VERSION/\${VISITARCH})" \
            >> $HOSTCONF
    fi
}

function bv_fides_ensure
{
    if [[ "$DO_FIDES" == "yes" ]] ; then
        ensure_built_or_ready "fides" $FIDES_VERSION $FIDES_BUILD_DIR $FIDES_FILE $FIDES_URL
        if [[ $? != 0 ]] ; then
            ANY_ERRORS="yes"
            DO_FIDES="no"
            error "Unable to build FIDES.  ${FIDES_FILE} not found."
        fi
    fi
}

# *************************************************************************** #
#                            Function 8, build_fides
# *************************************************************************** #
function build_fides
{
    #
    # Prepare build dir
    #
    prepare_build_dir $FIDES_BUILD_DIR $FIDES_FILE
    untarred_fides=$?
    if [[ $untarred_fides == -1 ]] ; then
        warn "Unable to prepare FIDES build directory. Giving Up!"
        return 1
    fi

    cd $FIDES_BUILD_DIR || error "Can't cd to FIDES source dir."
    mkdir build
    cd build || error "Can't cd to FIDES build dir."

    vopts="-DCMAKE_C_COMPILER:STRING=${C_COMPILER}"
    vopts="${vopts} -DCMAKE_C_FLAGS:STRING=\"${C_OPT_FLAGS}\""
    vopts="${vopts} -DCMAKE_INSTALL_PREFIX:PATH=${VISITDIR}/fides/${FIDES_VERSION}/${VISITARCH}"

    vopts="${vopts} -DVTKM_DIR=${VISITDIR}/vtkm/${VTKM_VERSION}/${VISITARCH}"
    vopts="${vopts} -DVTKm_DIR=${VISITDIR}/vtkm/${VTKM_VERSION}/${VISITARCH}"

    if test "x${DO_STATIC_BUILD}" = "xyes" ; then
        vopts="${vopts} -DBUILD_SHARED_LIBS:BOOL=OFF"
    else
        vopts="${vopts} -DBUILD_SHARED_LIBS:BOOL=ON"
    fi

    #
    # Call configure
    #
    info "Configuring FIDES . . ."
    CMAKE_BIN="${CMAKE_INSTALL}/cmake"
    if test -e bv_run_cmake.sh ; then
        rm -f bv_run_cmake.sh
    fi
    echo "\"${CMAKE_BIN}\" ${vopts} .." > bv_run_cmake.sh
    cat bv_run_cmake.sh
    issue_command bash bv_run_cmake.sh || error "FIDES configuration failed."

    #
    # Build FIDES
    #
    info "Building FIDES . . . (~2 minutes)"
    $MAKE $MAKE_OPT_FLAGS
    if [[ $? != 0 ]] ; then
        warn "FIDES build failed.  Giving up"
        return 1
    fi

    #
    # Install into the VisIt third party location.
    #
    info "Installing FIDES"
    $MAKE install

    if [[ "$DO_GROUP" == "yes" ]] ; then
        chmod -R ug+w,a+rX "$VISITDIR/fides"
        chgrp -R ${GROUP} "$VISITDIR/fides"
    fi
    cd "$START_DIR"
    info "Done with FIDES"
    return 0
}


function bv_fides_is_enabled
{
    if [[ $DO_FIDES == "yes" ]]; then
        return 1
    fi
    return 0
}

function bv_fides_is_installed
{
    check_if_installed "fides" $FIDES_VERSION
    if [[ $? == 0 ]] ; then
        return 1
    fi
    return 0
}

function bv_fides_build
{
    cd "$START_DIR"
    if [[ "$DO_FIDES" == "yes" ]] ; then
        check_if_installed "fides" $FIDES_VERSION
        if [[ $? == 0 ]] ; then
            info "Skipping FIDES build.  FIDES is already installed."
        else
            info "Building FIDES (~2 minutes)"
            build_fides
            if [[ $? != 0 ]] ; then
                error "Unable to build or install FIDES.  Bailing out."
            fi
            info "Done building FIDES"
        fi
    fi
}
