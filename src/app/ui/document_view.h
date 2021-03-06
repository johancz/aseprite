// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifndef APP_UI_DOCUMENT_VIEW_H_INCLUDED
#define APP_UI_DOCUMENT_VIEW_H_INCLUDED
#pragma once

#include "app/ui/tabs.h"
#include "app/ui/workspace_view.h"
#include "doc/document_observer.h"
#include "ui/box.h"

namespace ui {
  class View;
}

namespace app {
  class Document;
  class DocumentLocation;
  class Editor;

  class DocumentView : public ui::Box
                     , public TabView
                     , public doc::DocumentObserver
                     , public WorkspaceView {
  public:
    enum Type {
      Normal,
      Preview
    };

    DocumentView(Document* document, Type type);
    ~DocumentView();

    Document* getDocument() const { return m_document; }
    void getDocumentLocation(DocumentLocation* location) const;
    Editor* getEditor() { return m_editor; }

    // TabView implementation
    std::string getTabText() override;

    // WorkspaceView implementation
    ui::Widget* getContentWidget() override { return this; }
    WorkspaceView* cloneWorkspaceView() override;
    void onWorkspaceViewSelected() override;
    void onClonedFrom(WorkspaceView* from) override;

    // DocumentObserver implementation
    void onGeneralUpdate(doc::DocumentEvent& ev) override;
    void onSpritePixelsModified(doc::DocumentEvent& ev) override;
    void onLayerMergedDown(doc::DocumentEvent& ev) override;
    void onAddLayer(doc::DocumentEvent& ev) override;
    void onBeforeRemoveLayer(doc::DocumentEvent& ev) override;
    void onAddFrame(doc::DocumentEvent& ev) override;
    void onRemoveFrame(doc::DocumentEvent& ev) override;
    void onTotalFramesChanged(doc::DocumentEvent& ev) override;
    void onLayerRestacked(doc::DocumentEvent& ev) override;

  protected:
    bool onProcessMessage(ui::Message* msg) override;

  private:
    Document* m_document;
    ui::View* m_view;
    Editor* m_editor;
  };

} // namespace app

#endif
