#ifndef FACULTY_DIRECTION_H
#define FACULTY_DIRECTION_H

#include <algorithm>

#include "applicant.h"
#include "namespaces.h"

class FacultyDirection
{
public:
    FacultyDirection() noexcept = default;

    [[nodiscard]] const QString& name() const;
    void setName(const QString& newName);

    [[nodiscard]] const QString& division() const;
    void setDivision(const QString& newName);

    [[nodiscard]] int capacity() const;
    void setCapacity(int newCapacity);

    [[nodiscard]] const QString& code() const;
    void setCode(const QString& newCode);

    [[nodiscard]] const StudyForm& studyForm() const;
    void setStudyForm(const StudyForm& newStudyForm);

    [[nodiscard]] const StudyType& studyType() const;
    void setStudyType(const StudyType& newType);

    [[nodiscard]] const QList<QPair<PriorityInfo, Applicant>>& pool() const;
    void setPool(const QList<QPair<PriorityInfo, Applicant>>& newPool);
    void addToPool(const PriorityInfo& priority, const Applicant& applicant);

    [[nodiscard]] bool isAbleToAdd(const PriorityInfo& priority) const;

    [[nodiscard]] QPair<PriorityInfo, Applicant*> getUnsuitableApplicant();

    [[nodiscard]] int getPoolSize() const;

    friend QDataStream& operator<<(QDataStream& out, const FacultyDirection& p);
    friend QDataStream& operator>>(QDataStream& in, FacultyDirection& p);

private:
    int m_capacity;
    QString m_division;
    QString m_name;
    QString m_code;
    StudyForm m_studyForm = StudyForm::Uninitialized; // Personal, Personal-NotPersonal,...
    StudyType m_studyType = StudyType::Uninitialized; // Budget, NonBudget,...
    QList<QPair<PriorityInfo, Applicant>> m_pool;
};

#endif // FACULTY_DIRECTION_H
