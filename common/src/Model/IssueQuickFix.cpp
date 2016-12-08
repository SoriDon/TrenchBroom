/*
 Copyright (C) 2010-2016 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#include "IssueQuickFix.h"

#include "Model/Issue.h"

namespace TrenchBroom {
    namespace Model {
        IssueQuickFix::IssueQuickFix(const IssueType issueType, const String& description) :
        m_issueType(issueType),
        m_description(description) {}

        IssueQuickFix::~IssueQuickFix() {}
        
        const String& IssueQuickFix::description() const {
            return m_description;
        }
        
        void IssueQuickFix::apply(MapFacade* facade, const IssueList& issues) const {
            doApply(facade, issues);
        }

        void IssueQuickFix::doApply(MapFacade* facade, const IssueList& issues) const {
            IssueList::const_iterator it, end;
            for (it = std::begin(issues), end = std::end(issues); it != end; ++it) {
                const Issue* issue = *it;
                if (issue->type() == m_issueType)
                    doApply(facade, issue);
            }
        }
        
        void IssueQuickFix::doApply(MapFacade* facade, const Issue* issue) const {
            assert(false);
        }
    }
}
