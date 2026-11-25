#ifndef APPLICANTSTATSPROJECT_PRIORITYINFO_H
#define APPLICANTSTATSPROJECT_PRIORITYINFO_H

#include "namespaces.h"
#include "qdebug.h"

class PriorityInfo
{
public:
    PriorityInfo() noexcept = default;

    bool operator==(const PriorityInfo& copy) const;
    bool operator!=(const PriorityInfo& copy) const;
    bool operator<(const PriorityInfo& copy) const;
    bool operator>(const PriorityInfo& copy) const;
    bool operator<=(const PriorityInfo& copy) const;
    bool operator>=(const PriorityInfo& copy) const;

    [[nodiscard]] int egeScore() const;
    void setEgeScore(int newEgeScore);

    [[nodiscard]] int egeAdditionalScore() const;
    void setEgeAdditionalScore(int newEgeAdditionalScore);

    [[nodiscard]] int priorityNumber() const;
    void setPriorityNumber(int newPriorityNumber);

    [[nodiscard]] const QString& code() const;
    void setCode(const QString& newCode);

    [[nodiscard]] const QString& name() const;
    void setName(const QString& newName);

    [[nodiscard]] const QList<int>& subjectScores() const;
    void setSubjectScores(const QList<int>& newSubjectScores);
    void addSubject(int score);

    [[nodiscard]] int id() const;
    void setId(int newId);

    [[nodiscard]] bool admissionFlag() const;
    void setAdmissionFlag(bool newAdmissionsFlag);

    [[nodiscard]] bool isBVI() const;
    void setIsBVI(bool newIsBVI);

    [[nodiscard]] const QString& division() const;
    void setDivision(const QString& newDivision);

    [[nodiscard]] StudyForm studyForm() const;
    void setStudyForm(const StudyForm& newStudyForm);

    [[nodiscard]] StudyType studyType() const;
    void setStudyType(const StudyType& newType);

    friend QDataStream& operator<<(QDataStream& out, const PriorityInfo& p);
    friend QDataStream& operator>>(QDataStream& in, PriorityInfo& p);

private:
    int m_id;
    int m_egeScore;
    int m_egeAdditionalScore;
    int m_priorityNumber;
    QString m_code;
    QString m_name;
    QString m_division;
    QList<int> m_subjectScores;
    bool m_admissionFlag;
    bool m_isBVI;
    StudyForm m_studyForm = StudyForm::Uninitialized; // Personal, Personal-NotPersonal,...
    StudyType m_studyType = StudyType::Uninitialized; // Budget, NonBudget,...
};

#endif // APPLICANTSTATSPROJECT_PRIORITYINFO_H
