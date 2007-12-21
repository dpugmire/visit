/*****************************************************************************
*
* Copyright (c) 2000 - 2007, The Regents of the University of California
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef PLUGINMANAGERATTRIBUTES_H
#define PLUGINMANAGERATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: PluginManagerAttributes
//
// Purpose:
//    This class contains attributes for managing plugins.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Thu Dec 20 09:40:41 PDT 2007
//
// Modifications:
//   
// ****************************************************************************

class STATE_API PluginManagerAttributes : public AttributeSubject
{
public:
    PluginManagerAttributes();
    PluginManagerAttributes(const PluginManagerAttributes &obj);
    virtual ~PluginManagerAttributes();

    virtual PluginManagerAttributes& operator = (const PluginManagerAttributes &obj);
    virtual bool operator == (const PluginManagerAttributes &obj) const;
    virtual bool operator != (const PluginManagerAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectName();
    void SelectType();
    void SelectVersion();
    void SelectId();
    void SelectEnabled();

    // Property setting methods
    void SetName(const stringVector &name_);
    void SetType(const stringVector &type_);
    void SetVersion(const stringVector &version_);
    void SetId(const stringVector &id_);
    void SetEnabled(const intVector &enabled_);

    // Property getting methods
    const stringVector &GetName() const;
          stringVector &GetName();
    const stringVector &GetType() const;
          stringVector &GetType();
    const stringVector &GetVersion() const;
          stringVector &GetVersion();
    const stringVector &GetId() const;
          stringVector &GetId();
    const intVector    &GetEnabled() const;
          intVector    &GetEnabled();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    int GetIndexByID(const std::string &s);
    void AddPlugin(const std::string &n,const std::string &t,const std::string &v,const std::string &i,bool e);
    void RemovePlugin(const std::string &s);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_name = 0,
        ID_type,
        ID_version,
        ID_id,
        ID_enabled
    };

private:
    stringVector name;
    stringVector type;
    stringVector version;
    stringVector id;
    intVector    enabled;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
};

#endif
