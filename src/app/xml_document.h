// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifndef APP_XML_DOCUMENT_H_INCLUDED
#define APP_XML_DOCUMENT_H_INCLUDED
#pragma once

#include "base/exception.h"
#include "base/shared_ptr.h"

#include "tinyxml.h"

#include <string>

namespace app {

  typedef SharedPtr<TiXmlDocument> XmlDocumentRef;

  XmlDocumentRef open_xml(const std::string& filename);
  void save_xml(XmlDocumentRef doc, const std::string& filename);

} // namespace app

#endif
