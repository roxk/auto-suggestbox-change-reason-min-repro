#pragma once

#include "SuggestionViewModel.h"
#include "SuggestionViewModelWithoutToString.h"
#include "MainPage.g.h"

namespace winrt::AutoSuggestBoxTextChangeReasonUwp::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();
        Windows::Foundation::Collections::IObservableVector<IInspectable> Suggestions() { return mSuggestions; }
        Windows::Foundation::Collections::IObservableVector<IInspectable> SuggestionWithoutToStrings() { return mSuggestionWithoutToStrings; }
        void AutoSuggestBox_TextChanged(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs const& args);
        void AutoSuggestBox_SuggestionChosen(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args);
        void AutoSuggestBox_QuerySubmitted(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs const& args);
        void AutoSuggestBox_TextChanged_Without_ToString(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs const& args);
        void AutoSuggestBox_SuggestionChosen_Without_ToString(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args);
        void AutoSuggestBox_QuerySubmitted_Without_ToString(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs const& args);
    private:
        Windows::Foundation::Collections::IObservableVector<IInspectable> mSuggestions;
        Windows::Foundation::Collections::IObservableVector<IInspectable> mSuggestionWithoutToStrings;
        Windows::Foundation::IAsyncAction UpdateSuggestions(hstring query);
        Windows::Foundation::IAsyncAction UpdateSuggestionWithoutToStrings(hstring query);
    };
}

namespace winrt::AutoSuggestBoxTextChangeReasonUwp::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
